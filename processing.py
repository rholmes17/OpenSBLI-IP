import plot
import settings
import csv

arguments = settings.getSimArgs()


class RunData:
    def __init__(self):
        self.args = []

        self.t = []
        self.Enstrophy = []
        self.KE = []
        self.KEDR = []

        self.wallTime = 0


currentRun = RunData()

time = []
error = []
order = []
coreCount = []
wallTime = []
runId = []

with open(arguments.dataLog, 'r') as f:
    data_list = list(csv.reader(f))

    # Initialise first run of data
    for i in range(10):
        currentRun.args.append(data_list[1][i])

    for i in range(1, len(data_list)):
        rowSettings = []
        for j in range(10):
            # print(f"i = {i}, j = {j}")
            rowSettings.append(data_list[i][j])


        # Check if still reading data from the same run
        if currentRun.args == rowSettings and i != len(data_list)-1:
            # print(data_list[i])
            currentRun.t.append(data_list[i][10])
            currentRun.Enstrophy.append(data_list[i][11])
            currentRun.KE.append(data_list[i][12])
            currentRun.KEDR.append(data_list[i][13])
        else:
            print("new run")

            with open(arguments.timingLog, 'r') as tf:
                print(f"Opening timing file {arguments.timingLog}")
                reader = csv.reader(tf)
                for i, row in enumerate(reader):
                    #print(row)
                    if i > 0:
                        wallTime.append(float(row[-1]))
                        coreCount.append(int(row[-4]))
                        runId.append(int(row[0]))
                    # print(row[:-1] == currentRun.args)
                    if row[:-1] == currentRun.args:
                        print(f"Wall Time is {row[-1]}s")
                        currentRun.wallTime = row[-1]


            # Deal with data before it gets wiped
            time.append(currentRun.wallTime)
            # print(currentRun.t)
            error.append(plot.calc_error(currentRun.t, currentRun.KE, currentRun.KEDR))
            order.append(currentRun.args[8])


            currentRun.args = rowSettings
            del currentRun.t[:]
            del currentRun.Enstrophy[:]
            del currentRun.KE[:]
            del currentRun.KEDR[:]

print("Plotting")
plot.plot_cost(time, error, order)
# plot.plot_cores(coreCount, wallTime, runId)
