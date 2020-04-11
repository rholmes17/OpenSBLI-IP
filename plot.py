# Python 3
# Store functions used by process.py and
# postproc.py to interpret and plot data

from scipy import integrate
from math import factorial, fsum
from shutil import move, copyfile
import re
from os.path import isfile, join
from os import listdir
import h5py
from matplotlib import animation
import matplotlib.pyplot as plt
import numpy as np
import matplotlib

# Configure matplotlib
matplotlib.use('GTK3Agg')
plt.style.use('classic')
plt.figure(num=None, figsize=(10, 6), dpi=80, facecolor='w', edgecolor='k')


def read_file(fname):
    f = h5py.File(fname, 'r')
    group = f["opensbliblock00"]
    return f, group


def read_dataset(group, dataset, halo):
    d_m = group["%s" % (dataset)].attrs['d_m']
    size = group["%s" % (dataset)].shape
    read_start = [abs(d+halo) for d in d_m]
    read_end = [s-abs(d+halo) for d, s in zip(d_m, size)]
    # print(read_start)
    # print(read_end)
    if len(read_end) == 2:
        read_data = group["%s" % (dataset)].value[read_start[0]:read_end[0],
                                                  read_start[1]:read_end[1]]
    elif len(read_end) == 3:
        read_data = group["%s" % (dataset)][read_start[0]:read_end[0],
                                            read_start[1]:read_end[1],
                                            read_start[2]:read_end[2]]
    else:
        raise NotImplementedError("")
    return read_data


def extract_flow_variables(group, halo):
    gamma = 1.4
    # Read in the conservative variables
    rho = read_dataset(group, "rho_B0", halo)
    rhou = read_dataset(group, "rhou0_B0", halo)
    rhov = read_dataset(group, "rhou1_B0", halo)
    rhow = read_dataset(group, "rhou2_B0", halo)
    rhoE = read_dataset(group, "rhoE_B0", halo)

    # Velocity components u0, u1, u2
    u = rhou/rho
    v = rhov/rho
    w = rhow/rho
    # Pressure
    p = (gamma - 1)*(rhoE - 0.5*(u**2+v**2+w**2)*rho)
    return rho, u, v, w, p


def calc_derivative(var, direction, d_size, order):
    """ Function template to calculate derivatives. The return value should be
    a 3D NumPy array with one derivative value for each grid point."""
    der = np.zeros_like(var)
    halo = int(order/2)
    invh = (d_size-1)/np.pi

    derivative = 1

    p = int(order/2)
    size = 2*p+1

    A = np.zeros((size, size))
    b = np.zeros(size)

    for i, row in enumerate(A):
        for j, col in enumerate(range(-p, p+1)):
            A[i][j] = col**i

    b[derivative] = factorial(derivative)

    x = np.linalg.solve(A, b)

    if direction == 0:  # Calculate x-derivative
        for i in range(halo, d_size+halo):
            der[:, :, i] = 0
            for ite, p in enumerate(range(-int(order/2), int(order/2)+1)):
                der[:, :, i] += invh*x[ite]*var[:, :, i+p]

    elif direction == 1:  # Calculate y-derivative
        for j in range(halo, d_size+halo):
            der[:, j, :] = 0
            for ite, p in enumerate(range(-int(order/2), int(order/2)+1)):
                der[:, j, :] += invh*x[ite]*var[:, j+p, :]

    elif direction == 2:  # Calculate z-derivative
        for k in range(halo, d_size+halo):
            der[k, :, :] = 0
            for ite, p in enumerate(range(-int(order/2), int(order/2)+1)):
                der[k, :, :] += invh*x[ite]*var[k+p, :, :]

    else:
        raise ValueError("Direction should either be 0, 1, or 2.")

    return der


def main_plot(file_no, simulation_times, path, Re, grid, order):
    """ This is the main plot function to perform the coursework. 
    The intermediate solution files are read in and looped over below."""

    halo = int(order/2)
    print(f"Grid of size {grid} and running an order of {order}")
    print("Processing simulation data in file", path)
    print("Processing simulation data at time t=%.2f" % simulation_times)
    # Open the file
    f, group = read_file(path)
    # Extract the primitive flow variables
    rho, u, v, w, p = extract_flow_variables(group, halo)
    print("The shape of the output data with halo points is: (%d, %d, %d)" %
          np.shape(rho))
    # Demonstrating how to index only the points inside the domain
    p_without_halos = p[halo:-halo-1, halo:-halo-1, halo:-halo-1]
    p_mean = np.sum(p_without_halos)/np.size(p_without_halos)
    print("Average value of pressure over the domain is %.8f" % p_mean)

    ke_with_halos = 0.5*(u**2+v**2+w**2)
    ke_without_halos = ke_with_halos[halo:-halo-1, halo:-halo-1, halo:-halo-1]
    ke_mean = np.sum(ke_without_halos)/np.size(ke_without_halos)
    print("KE mean is %.8f" % ke_mean)

    # Calculate the derivatives for the velocities (not all used)
    # dudx = calc_derivative(u, 0, grid, order)
    dudy = calc_derivative(u, 1, grid, order)
    dudz = calc_derivative(u, 2, grid, order)

    dvdx = calc_derivative(v, 0, grid, order)
    # dvdy = calc_derivative(v, 1, grid, order)
    dvdz = calc_derivative(v, 2, grid, order)

    dwdx = calc_derivative(w, 0, grid, order)
    dwdy = calc_derivative(w, 1, grid, order)
    # dwdz = calc_derivative(w, 2, grid, order)

    # Calculate vorticity
    vortx = dwdy - dvdz
    vorty = dudz - dwdx
    vortz = dvdx - dudy

    # Calculate enstrophy from vorticiy, remove the halos,
    # and average over simulation volume
    enst_with_halos = vortx**2+vorty**2+vortz**2
    enst_without_halos = enst_with_halos[halo:-halo-1,
                                         halo:-halo-1,
                                         halo:-halo-1]
    enst_mean = np.sum(enst_without_halos)/np.size(enst_without_halos)

    kedr = enst_mean / Re

    print("Enstrophy =", enst_mean)

    # Find maximum velocity magnitude
    mag = (u**2+v**2+w**2)**0.5
    print(f"Maximum velocity magnitude = {mag.max()}")

    # Store maximum velocity magnitude out of curiosity
    with open('v.csv', 'a') as vf:
        vf.write(f"{mag.max()},")

    # Close the file before opening the next one
    f.close()

    return enst_mean, ke_mean, kedr


# Obtain useful data from file
def plot_file(path, dt, Re, grid, niter, saveFreq, order):

    print("Plotting file " + path)

    currentIterationStr = path[-9:-3]

    t = int(currentIterationStr) * dt
    file_no = int(currentIterationStr) - saveFreq

    # Call the main plot function
    enstrophy, KE, KEDR = main_plot(file_no, t, path, Re, grid, order)

    return enstrophy, KE, KEDR, t


# Calculate error from input, different errors can be specified
def calc_error(t, dKE_dtSelf, KEDRSelf, enstSelf=0,
               dKE_dtBench=0, KEDRBench=0, enstBench=0, errorType="Self"):

    error = []
    if errorType == "Self":
        for i in range(len(t)-2):
            error.append(abs(dKE_dtSelf[i]-KEDRSelf[i]))
        errorSum = fsum(error)/len(error)
    elif errorType == "BenchEnst":
        errorSum = abs(fsum(enstBench)/len(enstBench) -
                       fsum(enstSelf)/len(enstSelf))
    elif errorType == "BenchdKE_dt":
        errorSum = abs(fsum(dKE_dtBench)/len(dKE_dtBench) -
                       fsum(dKE_dtSelf)/len(dKE_dtSelf))
    elif errorType == "BenchKEDR":
        errorSum = abs(fsum(KEDRBench)/len(KEDRBench) -
                       fsum(KEDRSelf)/len(KEDRSelf))
    else:
        raise Exception("Invalid error type")

    return errorSum, error


# Display error over time using matplotlib
def plot_error(t, error, KEDR, dKE_dt):
    plt.plot(t[1:-1], dKE_dt, label=r"$\frac{dE_K}{dt}$")
    plt.plot(t, KEDR, label=r"$\frac{dE_K}{dt}|_{Enst}$")
    plt.plot(t[1:-1], error, label="Error")
    plt.xlabel('Time')
    plt.ylim(bottom=0)
    plt.legend()
    plt.show()


# Display error over time using matplotlib
def plot_consecutive_error(t, error, KEDR, dKE_dt, order):
    fig, axs = plt.subplots(1, len(order), figsize=(14, 6),
                            facecolor='w', edgecolor='k')

    for i, o in enumerate(order):
        axs[i].plot(t[i][1:-1], dKE_dt[i], label=r"$\frac{dE_K}{dt}$")
        axs[i].plot(t[i], KEDR[i], label=r"$\frac{dE_K}{dt}|_{Enst}$")
        axs[i].plot(t[i][1:-1], error[i], label="Error")
        axs[i].set_ylim(0, 0.014)
        axs[i].set_xlabel('Time')
        if o % 10 == 2:
            axs[i].set_title(str(o)+r"$^{nd}$ order")
        else:
            axs[i].set_title(str(o)+r"$^{th}$ order")
        axs[i].grid(True)
    fig.tight_layout()
    axs[0].legend(loc=2)
    plt.show()


# Perform second order central differencing to find the time derivative of KE
def DerKE(t, KE):
    dKE_dt = []
    for k in range(1, len(t)-1):
        dKE_dt.append(-(KE[k+1]-KE[k-1])/(t[k+1]-t[k-1]))
    return dKE_dt


# Display velocity field at an xy plane at the given z
def plot_quiver(grid, velocity, z):
    X = np.arange(1, grid+1, 1)
    Y = np.arange(1, grid+1, 1)
    U = velocity[0, :, :, z, 0]
    V = velocity[0, :, :, z, 1]
    fig, ax = plt.subplots()
    q = ax.quiver(X, Y, U, V)
    plt.ylim(0, grid+1)
    plt.xlim(0, grid+1)
    plt.show()


# Record an animation of the velocity field at z
def plot_animated_quiver(grid, velocity, z):
    # Each value in the velocity array represents:
    #           t,x,y,z,dir
    # velocity[-1,:,:,7,0]
    X = np.arange(1, grid+1, 1)
    Y = np.arange(1, grid+1, 1)

    U = velocity[0, :, :, z, 0]
    V = velocity[0, :, :, z, 1]

    fig, ax = plt.subplots()
    q = ax.quiver(X, Y, U, V)
    plt.ylim(0, grid+1)
    plt.xlim(0, grid+1)

    anim = animation.FuncAnimation(fig, update_quiver, fargs=(q, velocity, z),
                                   interval=50, frames=velocity.shape[0],
                                   blit=False)
    anim.save(f"{grid} sym anim quiver.mp4", bitrate=12000)
    plt.show()


# Updates the horizontal and vertical vector components by a given increment
def update_quiver(num, Q, velocity, z):
    U = velocity[num, :, :, z, 0]
    V = velocity[num, :, :, z, 1]

    Q.set_UVC(U, V)

    return Q


# Plot error against cost with different orders colour coded and labeled
def plot_cost(t, error, order, ylog=False, xlog=False):
    colour = {2: "green", 4: "blue", 6: "red", 8: "black", 10: "yellow"}
    for o in sorted(set(order)):
        x = []
        for i, time in enumerate(t):
            if order[i] == o:
                x.append(float(time))

        y = []
        for i, err in enumerate(error):
            if order[i] == o:
                y.append(float(err))

        # Generate random colours for other orders
        cmap = plt.get_cmap('gist_rainbow')
        if o not in colour:
            colour[o] = cmap(np.random.rand(1))

        if o % 10 == 2:
            plt.scatter(x, y, c=colour[o], label=f"{o}nd order")
        else:
            plt.scatter(x, y, c=colour[o], label=f"{o}th order")

    if ylog:
        plt.yscale("log")
    else:
        plt.ylim(bottom=0)

    if xlog:
        plt.xscale("log")
    else:
        plt.xlim(left=0)

    plt.title("Error against grid size for different "
              "orders of central difference scheme")
    plt.xlabel("Wall Time (s)")
    plt.ylabel("Error")
    plt.legend()
    plt.grid(True)
    plt.show()


# Plot error against order
def plot_order(error, order, grid, ylog=False, xlog=False):
    colour = {17: "k", 33: "w", 65: "red"}
    if len(set(grid)) == 1:
        plt.scatter(order, error)

    else:
        for g in sorted(set(grid)):
            x = []
            y = []
            for i, e in enumerate(error):
                if grid[i] == g:
                    x.append(order[i])
                    y.append(e)
            plt.scatter(x, y, c=colour[g], label=f"{g}$^3$ grid")

    if ylog:
        plt.yscale("log")
        plt.ylim(top=0.0001)
        # plt.ylim(bottom=0.001)
    else:
        # plt.ylim(top=0.0005)
        plt.ylim(bottom=0)

    if xlog:
        plt.xscale("log")

    # plt.title("Error against different orders of central difference scheme")
    plt.xlabel("Order")
    plt.ylabel("Error")
    plt.grid(True)
    plt.legend()
    plt.show()


# Plot time taken against number of threads used
def plot_cores(cores, t, order):
    colour = {2: "yellow", 4: "c", 6: "red", 8: "w", 10: "k"}
    for o in sorted(set(order)):
        y = []
        for i, time in enumerate(t):
            if order[i] == o:
                y.append(float(time))

        x = []
        for i, core in enumerate(cores):
            if order[i] == o:
                x.append(float(core))

        if o % 10 == 2:
            plt.scatter(x, y, c=colour[o], label=f"{o}nd order")
        else:
            plt.scatter(x, y, c=colour[o], label=f"{o}th order")

    # plt.scatter(cores, t)
    plt.ylim(bottom=0)
    plt.ylabel("Wall time (s)")
    plt.xlabel("Number of Threads")
    plt.legend(loc=0)
    plt.grid(True)
    plt.show()
