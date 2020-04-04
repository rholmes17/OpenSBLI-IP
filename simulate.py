# Python 2.7
# Run simulation and output data to current directory
# Record wall time for each run in a csv file

# Libraries
import os
import subprocess
import time
import csv

# Files
import settings
import tgv

runId = 0
arguments = settings.getSimArgs()

for i in range(arguments.runCount):
    arguments.useCFL()

    os.system("rm -f opensbli_output*")

    # Prepare string to run solver using specified number of cores
    mpirunString = "mpirun -np " + str(arguments.coreCount) + " opensbli_mpi"

    # Check if file for logging time exists
    if (not os.path.exists(arguments.timingLog)):
        # Create timning file with headers
        with open(arguments.timingLog, 'w') as f:
            fieldnames = ['id', 'dt', 'niter', 'Re', 'gama',
                          'Minf', 'Pr', 'Core Count', 'order', 'grid', 'time']
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()
        print("File created for logging timings")

    # Clean directory
    os.system("make clean")

    # Print settings that will be run
    print("Grid Size: {0}".format(str(arguments.grid)))
    print("Reynolds Number: {0}".format(str(arguments.Re)))
    print("Time step: {0}".format(str(arguments.dt)))
    print("Number of iterations: {0}".format(str(arguments.niter)))

    # Configure OpenSBLI
    tgv.tgv(arguments.grid, arguments.Re, arguments.dt, arguments.niter,
            order=arguments.order, saveFreq=arguments.saveFreq)

    # Use OPS to generate files
    os.system("python $OPS_TRANSLATOR opensbli.cpp")

    # Prepare MPI
    os.system("make opensbli_mpi")

    # Use MPI to run simulation and measure time taken
    startTime = time.time()
    os.system(mpirunString)
    endTime = time.time()
    print("Time taken to run is: {0}".format(endTime - startTime))

    # Open existing timing log for reading
    with open(arguments.timingLog, 'r') as f:
        data_list = list(csv.reader(f))
        # If there is already data, set runID to the next one
        if (len(data_list) > 1):
            runId = int(data_list[-1][0]) + 1

    # Open file to append data
    with open(arguments.timingLog, 'a') as f:

        f.write("{0},".format(runId))

        f.write("{:.10g},".format(arguments.dt))
        f.write("{0},".format(arguments.niter))

        f.write("{0},".format(arguments.Re))
        f.write("{0},".format(arguments.gama))
        f.write("{0},".format(arguments.Minf))
        f.write("{0},".format(arguments.Pr))

        f.write("{0},".format(arguments.coreCount))

        f.write("{0},".format(arguments.order))
        f.write("{0},".format(arguments.grid))

        f.write(str(endTime - startTime))

        f.write('\n')

    arguments.iterate()
