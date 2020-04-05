# Store settings used in simulations and how they will change on each iteration

from numpy import pi


def getSimArgs():
    return SimulationArguments()


class SimulationArguments:
    def __init__(self):
        self.coreCount = 4

        self.dt = 0.005         # 0.005     0.0025
        self.niter = 4000       # 4000      8000 for 63 sym
        self.saveFreq = 50      # 50

        self.Re = 800.          # 800.
        self.gama = 1.4         # 1.4
        self.Minf = 0.1         # 0.1
        self.Pr = 0.71          # 0.71

        self.order = 4          # 4
        self.grid = 33          # Odd number (17, 33, 65)

        self.CFL = 0.1          # Not the actual CFL number
        self.runCount = 1       # Number of runs in batch

        # Choose name for the files where data will be stored
        fileEnding = "Test"
        self.timingLog = "Timings"+fileEnding+".csv"
        self.dataLog = "Data"+fileEnding+".csv"

        # Benchmark file must only have one run
        self.benchmarkFile = "DataBenchmark.csv"

    def iterate(self):
        # Iterate through order and then grid size
        # if self.order == 8:
        #     self.grid += 8
        #     self.order = 2
        # else:
        #     self.order += 2

        # Iterate through order, then number of threads
        if self.order == 10:
            self.coreCount += 1
            self.order = 2
        else:
            self.order += 2

        # Iterate through orders
        # self.order -= 2

    # Use CFL condition to calculate time step and number of iterations
    def useCFL(self):
        endTime = 2        # 20  Non-dimensionalised time when simulation ends
        numberOfPoints = 1  # 80  Used for calculating save frequency

        # Using max v=2.1 determined empirically (is not the right velocity)
        self.dt = self.CFL * (pi/(self.grid-1)) / 2.1
        self.niter = int(endTime/self.dt)

        self.saveFreq = int(self.niter/numberOfPoints)
