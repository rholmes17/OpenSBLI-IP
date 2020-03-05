# Stoer settings used in simulations


def getSimArgs():
    return SimulationArguments()


class SimulationArguments:
    def __init__(self):
        self.coreCount = 8

        
        self.dt = 0.005        # 0.005     0.0025
        self.niter = 4000       # 4000      8000 for 63s
        self.saveFreq = 50      # 50

        self.Re = 800.          # 800.
        self.gama = 1.4         # 1.4
        self.Minf = 0.1         # 0.1
        self.Pr = 0.71          # 0.71

        self.order = 4          # 4
        self.grid = 33          # Odd number (17, 33, 63)
