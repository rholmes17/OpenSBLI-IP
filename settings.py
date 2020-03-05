# Store settings used in simulations


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

        self.order = 2          # 4
        self.grid = 17          # Odd number (17, 33, 63)

        self.timingLog = "TimingLog.csv"
        self.dataLog = "Data.csv"

    def iterate(self):
        if self.order == 8:
            self.grid += 8
            self.order = 2
        else:
            self.order += 2
        # if self.order == 8:
        #     self.coreCount += 1
        #     self.order = 2
        # else:
        #     self.order += 2
