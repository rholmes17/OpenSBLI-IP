# Python 3
# Analyse data found in DataDump directory

import settings
import plot
import numpy as np
import csv
from time import perf_counter
import time
import os
from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler
import sys

arguments = settings.getSimArgs()


# class SimulationResults:
#     def __init__(self, files, grid):
#         self.enstrophy = np.zeros(files)
#         self.KE = np.zeros(files)
#         self.KEDR = np.zeros(files)
#         self.time = np.zeros(files)
#         self.velocity = np.zeros((files, grid, grid, grid, 3))


# fileQuantity = (arguments.niter / arguments.saveFreq)

# results = SimulationResults(int(fileQuantity), arguments.grid)

# start = perf_counter()

# directory = "./DataDump/" + str(arguments.grid) + "/"
# results.enstrophy, results.KE, results.KEDR, results.time, velocity = plot.plot_file(directory, arguments.dt, arguments.Re, arguments.grid)

# end = perf_counter()

# print(end - start)

#plot.plot_graphs(results.time, results.enstrophy, results.KE, results.KEDR, arguments.grid)

# plot.plot_quiver(arguments.grid, velocity[0,:,:,7,0],velocity[0,:,:,7,1])
# plot.plot_quiver_new(arguments.grid, velocity, 7)

# plot.plot_animated_quiver(arguments.grid, velocity, int((arguments.grid-1)/2))

# plot.plot_scatter()


if (not os.path.exists(arguments.dataLog)):
    with open(arguments.dataLog, 'w') as f:
        fieldnames = ['id', 'dt', 'niter', 'Re', 'gama', 'Minf', 'Pr', 'Core Count', 'order', 'grid', 'time', "Enstrophy", "Kinetic Energy", "Kinetic Energy Dissipation Rate"]
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()

    print("File created for logging runs")

print("Now waiting to analyse data")

runId = 0
if (os.path.exists(arguments.timingLog)):
    with open(arguments.timingLog, 'r') as f:
        data_list = list(csv.reader(f))
        if (len(data_list) > 1):
            runId = int(data_list[-1][0]) + 1

if __name__ == "__main__":
    patterns = "*"
    ignore_patterns = ""
    ignore_directories = True
    case_sensitive = True
    my_event_handler = PatternMatchingEventHandler(patterns, ignore_patterns, ignore_directories, case_sensitive)


def on_created(event):
    global runId
    h5files = []
    currentFilePath = "./"
    print(f"The file {event.src_path} has been created")
    if event.src_path[-3:] == ".h5":
        with os.scandir() as entries:
            for entry in entries:
                if entry.name[-3:] == ".h5":
                    # print(f"{entry.name} is in this directory")
                    h5files.append(entry.path)
        # print(len(h5files))
        if len(h5files) >= 2:
            # Check if the last file has been generated
            if event.src_path == "./opensbli_output.h5":
                currentFilePath = sorted(h5files)[1]
            else:
                currentFilePath = sorted(h5files)[0]

            print(f"\n{currentFilePath} has been selected for processing")
            enstrophy, ke, kedr, t = plot.plot_file(currentFilePath, arguments.dt, arguments.Re, arguments.grid, arguments.niter, arguments.saveFreq, arguments.order)

            with open(arguments.dataLog, 'a') as f:
                print(f"Writing to {arguments.dataLog}")

                f.write("{0},".format(runId))

                f.write("{0},".format(arguments.dt))
                f.write("{0},".format(arguments.niter))

                f.write("{0},".format(arguments.Re))
                f.write("{0},".format(arguments.gama))
                f.write("{0},".format(arguments.Minf))
                f.write("{0},".format(arguments.Pr))

                f.write("{0},".format(arguments.coreCount))

                f.write("{0},".format(arguments.order))
                f.write("{0},".format(arguments.grid))

                f.write(f"{t},")
                f.write(f"{enstrophy},")
                f.write(f"{ke},")
                f.write(f"{kedr}")
                f.write('\n')

            print(f"Removing {currentFilePath}")
            os.system(f"rm -f {currentFilePath}")
            print("")

        if event.src_path == "./opensbli_output.h5":
            print(f"Finished run\n")
            arguments.iterate()
            runId += 1


my_event_handler.on_created = on_created


path = "."
go_recursively = False
my_observer = Observer()
my_observer.schedule(my_event_handler, path, recursive=go_recursively)

my_observer.start()
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    my_observer.stop()
    my_observer.join()
