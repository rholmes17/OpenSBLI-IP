# Python 3
# Monitor created files and process them when they correspond
# with OpenBLI outputs, adding data to a csv

import settings
import plot
import numpy as np
import csv
from time import perf_counter
import time
import os
from math import isnan
from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler
import sys
import matplotlib.pyplot as plt

arguments = settings.getSimArgs()


# Create file to store data if it does not already exist
if (not os.path.exists(arguments.dataLog)):
    with open(arguments.dataLog, 'w') as f:
        fieldnames = ['id', 'dt', 'niter', 'Re', 'gama', 'Minf', 'Pr',
                      'Core Count', 'order', 'grid', 'time', "Enstrophy",
                      "Kinetic Energy", "Kinetic Energy Dissipation Rate"]
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()

    print("File created for logging runs")

print("Now waiting to analyse data")

# Use ID of current run using the latest from the timing log file if it exists
runId = 0
if (os.path.exists(arguments.timingLog)):
    with open(arguments.timingLog, 'r') as f:
        data_list = list(csv.reader(f))
        if (len(data_list) > 1):
            runId = int(data_list[-1][0]) + 1


# Set up live plot
plt.ion()

x = []
y = []

fig = plt.figure()
ax = fig.add_subplot(111)
line1, = ax.plot(x, y, 'r-')

ax.set_xlim(left=0)
ax.set_ylim(bottom=0)

ax.set_xlabel("Time")
ax.set_title("Kinetic Energy Dissipation Rate")

# Start timers
startTime = perf_counter()
currentRunTime = perf_counter()

# Set up an event handler to listen fotr changes in the directory
if __name__ == "__main__":
    patterns = "*"
    ignore_patterns = ""
    ignore_directories = True
    case_sensitive = True
    my_event_handler = PatternMatchingEventHandler(
        patterns, ignore_patterns, ignore_directories, case_sensitive)


# Run whenever a file is created in the directory
def on_created(event):
    global runId, x, y, startTime, currentRunTime
    h5files = []
    currentFilePath = "./"
    print(f"The file {event.src_path} has been created")
    if event.src_path[-3:] == ".h5":
        with os.scandir() as entries:
            for entry in entries:
                if entry.name[-3:] == ".h5":
                    h5files.append(entry.path)
        # print(len(h5files))
        if len(h5files) >= 2:
            # Check if the last file has been generated
            if event.src_path == "./opensbli_output.h5":
                currentFilePath = sorted(h5files)[1]
            else:
                currentFilePath = sorted(h5files)[0]

            print(f"\n{currentFilePath} has been selected for processing")
            timeSinceStart = perf_counter() - startTime
            timeSinceRun = perf_counter() - currentRunTime

            formattedTimeSinceStart = plot.FormatTime(timeSinceStart)
            formattedTimeSinceRun = plot.FormatTime(timeSinceRun)

            print(f"{(timeSinceStart): .2f}s",
                  "since the start of the batch,", end=" ")
            print(f"{(timeSinceRun):.2f}s since the start of the current run")

            print(f"{int(formattedTimeSinceStart[0])} days, ", end="")
            print(f"{int(formattedTimeSinceStart[1])} hours, ", end="")
            print(f"{int(formattedTimeSinceStart[2])} minutes, ", end="")
            print(f"and {formattedTimeSinceStart[3]: .2f} seconds",
                  "since the batch was started.")

            print(f"{int(formattedTimeSinceRun[0])} days,", end=" ")
            print(f"{int(formattedTimeSinceRun[1])} hours,", end=" ")
            print(f"{int(formattedTimeSinceRun[2])} minutes,", end=" ")
            print(f"and {formattedTimeSinceRun[3]: .2f} seconds",
                  "since this run was started.")

            # Change values to comply with CFL condition
            arguments.useCFL()

            enstrophy, ke, kedr, t = plot.plot_file(
                currentFilePath,
                arguments.dt,
                arguments.Re,
                arguments.grid,
                arguments.niter,
                arguments.saveFreq,
                arguments.order)

            with open(arguments.dataLog, 'a') as f:
                print(f"Writing to {arguments.dataLog}")

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

                f.write(f"{t},")
                f.write(f"{enstrophy},")
                f.write(f"{ke},")
                f.write(f"{kedr}")
                f.write('\n')

                if not isnan(kedr):
                    x.append(t)
                    y.append(kedr)

                    ax.set_xlim(right=x[-1])
                    ax.set_ylim(top=max(y))

                    line1.set_xdata(x)
                    line1.set_ydata(y)
                    fig.canvas.draw()
                    fig.canvas.flush_events()

            print(f"Removing {currentFilePath}")
            os.system(f"rm -f {currentFilePath}")
            print("")

        # Detect file that is generated at the end of a run
        if event.src_path == "./opensbli_output.h5":
            print(f"Finished run\n")
            arguments.iterate()
            runId += 1

            del x[:]
            del y[:]

            currentRunTime = perf_counter()


# Configure event handler
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
