# Python 2.7
# Run simulation and output data to DataDump directory

# Libraries
import os
import subprocess
import time
import csv

# Files
import settings
import tgv

arguments = settings.getSimArgs()

enstrophyList = []
KEDRList = []
tList = []

# Compile string to run solver using specified number of cores
mpirunString = "mpirun -np " + str(arguments.coreCount) + " opensbli_mpi"

directory = "./DataDump/" + str(arguments.grid) + "/"

# Check if directory exists to store data
if (os.path.exists(directory)):
    if len(os.listdir(directory)) != 0:
        raise Exception("Directory with files already exists in " + directory)
else:
    # Create new directory
    os.system("mkdir " + directory)
    print("New directory created " + directory)

# Check if file for logging time exists
logFile = "timingLog.csv"
if (not os.path.exists(logFile)):
    with open(logFile, 'w') as f:
        fieldnames = ['dt', 'niter', 'Re', 'gama', 'Minf', 'Pr', 'order', 'grid', 'time']
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()

    print("File created for logging timings")

os.system("make clean")

print("Grid Size: ", str(arguments.grid))
print("Reynolds Number: ", str(arguments.Re))
print("Time step: ", str(arguments.dt))
print("Number of iterations: ", str(arguments.niter))

tgv.tgv(arguments.grid, arguments.Re, arguments.dt, arguments.niter, order=arguments.order, saveFreq=arguments.saveFreq)

os.system("python $OPS_TRANSLATOR opensbli.cpp")
os.system("make opensbli_mpi")

startTime = time.time()
os.system(mpirunString)
endTime = time.time()
print("Time taken to run is: ", endTime - startTime)

with open(logFile, 'a') as f:
    f.write("{0},".format(arguments.dt))
    f.write("{0},".format(arguments.niter))

    f.write("{0},".format(arguments.Re))
    f.write("{0},".format(arguments.gama))
    f.write("{0},".format(arguments.Minf))
    f.write("{0},".format(arguments.Pr))

    f.write("{0},".format(arguments.order))
    f.write("{0},".format(arguments.grid))

    f.write(str(endTime - startTime))

    f.write('\n')

os.system("mv opensbli_output* " + directory)
weirdFile = directory + "opensbli_output.h5"
os.system("rm -f " + weirdFile)