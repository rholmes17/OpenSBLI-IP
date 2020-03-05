# Python 3
# Analyse data found in DataDump directory

import settings
import plot
import numpy as np
from time import perf_counter

arguments = settings.getSimArgs()


class SimulationResults:
    def __init__(self, files, grid):
        self.enstrophy = np.zeros(files)
        self.KE = np.zeros(files)
        self.KEDR = np.zeros(files)
        self.time = np.zeros(files)
        self.velocity = np.zeros((files, grid, grid, grid, 3))


fileQuantity = (arguments.niter / arguments.saveFreq)

results = SimulationResults(int(fileQuantity), arguments.grid)

start = perf_counter()

directory = "./DataDump/" + str(arguments.grid) + "/"
results.enstrophy, results.KE, results.KEDR, results.time, velocity = plot.plot_file(directory, arguments.dt, arguments.Re, arguments.grid)

end = perf_counter()

print(end - start)

plot.plot_graphs(results.time, results.enstrophy, results.KE, results.KEDR, arguments.grid)

# plot.plot_quiver(arguments.grid, velocity[0,:,:,7,0],velocity[0,:,:,7,1])
# plot.plot_quiver_new(arguments.grid, velocity, 7)

# plot.plot_animated_quiver(arguments.grid, velocity, int((arguments.grid-1)/2))

# plot.plot_scatter()