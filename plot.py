# plotAll.py

from scipy import integrate
from math import factorial
from shutil import move, copyfile
import re
from os.path import isfile, join
from os import listdir
import h5py
from matplotlib import animation
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
matplotlib.use('GTK3Agg')
# matplotlib.use('Agg')

plt.style.use('classic')


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
        read_data = group["%s" % (
            dataset)].value[read_start[0]:read_end[0], read_start[1]:read_end[1]]
    elif len(read_end) == 3:
        read_data = group["%s" % (dataset)][read_start[0]:read_end[0],
                                            read_start[1]:read_end[1], read_start[2]:read_end[2]]
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

    #print("rho =", rho[10, 10, 10], "rhou =", rhou[10][10][10], "rhov =", rhov[10][10][10], "rhow =", rhow[10][10][10], "rhoE =", rhoE[10][10][10])
    # print(rho)

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
    """ This is the main plot function to perform the coursework. The intermediate
    solution files are read in and looped over below."""

    halo = int(order/2)
    print(f"Grid of size {grid} and Halo nodes are of size {halo}")
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

    # Calculate all the derivatives for the velocities
    dudx = calc_derivative(u, 0, grid, order)
    dudy = calc_derivative(u, 1, grid, order)
    dudz = calc_derivative(u, 2, grid, order)

    dvdx = calc_derivative(v, 0, grid, order)
    dvdy = calc_derivative(v, 1, grid, order)
    dvdz = calc_derivative(v, 2, grid, order)

    dwdx = calc_derivative(w, 0, grid, order)
    dwdy = calc_derivative(w, 1, grid, order)
    dwdz = calc_derivative(w, 2, grid, order)

    # Calculate vorticity as cross product of del operator and velocity vector
    vortx = dwdy - dvdz
    vorty = dudz - dwdx
    vortz = dvdx - dudy

    # Calculate enstrophy from vorticiy, remove the halos, then average over simulation volume, then add to list for the run values
    enst_with_halos = vortx**2+vorty**2+vortz**2
    enst_without_halos = enst_with_halos[halo:-
                                         halo-1, halo:-halo-1, halo:-halo-1]
    enst_mean = np.sum(enst_without_halos)/np.size(enst_without_halos)

    kedr = enst_mean / Re

    print("Enstrophy =", enst_mean)

    # Find maximum velocity magnitude
    mag = (u**2+v**2+w**2)**0.5
    print(f"Maximum velocity magnitude = {mag.max()}")

    with open('v.csv', 'a') as vf:
        vf.write(f"{mag.max()},")

    # Close the file before opening the next one
    f.close()

    return enst_mean, ke_mean, kedr


def plot_file(path, dt, Re, grid, niter, saveFreq, order):

    print("Plotting file " + path)

    currentIterationStr = path[-9:-3]

    t = int(currentIterationStr) * dt
    file_no = int(currentIterationStr) - saveFreq

    # Call the main plot function
    enstrophy, KE, KEDR = main_plot(file_no, t, path, Re, grid, order)

    return enstrophy, KE, KEDR, t


def calc_error(t, KE, KEDR):

    dKE_dt = [KEDR[0]]
    error = [0]

    for k in range(1, len(t)-1):
        dKE_dt.append(-(KE[k+1]-KE[k-1])/(t[k+1]-t[k-1]))
        error.append(abs(dKE_dt[k]-KEDR[k]))

    # print(error)
    errorSum = 0
    for e in error:
        errorSum += e

    # maxErrorIndex = np.argmax(error)
    # Max error at error[maxErrorIndex]

    # print(len(dKE_dt))
    # print(len(t[0:-1]))
    newKE = []
    for i in range(len(t[0:-1])):
        newKE.append(-integrate.simps(dKE_dt[0:i+1], t[0:i+1]))

    # print(newKE)

    # plt.plot(t[:-1], dKE_dt, label="dKE_dt")
    # plt.show()

    # plt.plot(t, KE, label="KE")
    # plt.plot(t[:-1], newKE, label="Integral")
    # plt.xlabel('Time')
    # plt.ylim(bottom=0)
    # plt.legend()
    # plt.show()


    return errorSum/len(error), error, dKE_dt


def plot_error(t, error, KEDR, dKE_dt):
    plt.plot(t[:-1], dKE_dt, label="dKE_dt ")
    plt.plot(t, KEDR, label="KEDR ")
    plt.plot(t[:-1], error, label="error ")
    plt.xlabel('Time')
    plt.ylim(bottom=0)
    plt.legend()
    plt.show()


def plot_graphs(t, enstrophy, KE, KEDR, grid):

    dKE_dt = [float(KEDR[0])]
    error = [0]

    for k in range(1, len(t)-1):
        dKE_dt.append(-(KE[k+1]-KE[k-1])/(t[k+1]-t[k-1]))
        error.append(dKE_dt[k]-KEDR[k])
    print(error)
    errorSum = 0
    for e in error:
        errorSum += e

    maxErrorIndex = np.argmax(error)

    print("Integral of error =", errorSum)
    print("Maximum error of", error[maxErrorIndex], "at time",
          t[maxErrorIndex], "with index", maxErrorIndex)

    # plt.plot(t[:-1], dKE_dt, label="dKE_dt "+str(grid))
    plt.plot(t, KEDR, label="KEDR "+str(grid))
    plt.plot(t[:-1], error, label="error "+str(grid))
    plt.xlabel('Time')
    plt.ylim(bottom=0)
    plt.legend()
    plt.show()


def plot_quiver(grid, U, V):
    X = np.arange(1, grid+1, 1)
    Y = np.arange(1, grid+1, 1)

    fig, ax = plt.subplots()
    q = ax.quiver(X, Y, U, V)
    plt.ylim(0, grid+1)
    plt.xlim(0, grid+1)
    plt.show()


def plot_quiver_new(grid, velocity, z):
    X = np.arange(1, grid+1, 1)
    Y = np.arange(1, grid+1, 1)
    U = velocity[0, :, :, z, 0]
    V = velocity[0, :, :, z, 1]
    fig, ax = plt.subplots()
    q = ax.quiver(X, Y, U, V)
    plt.ylim(0, grid+1)
    plt.xlim(0, grid+1)
    plt.show()


def plot_animated_quiver(grid, velocity, z):
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
                                   interval=50, frames=velocity.shape[0], blit=False)
    anim.save(f"{grid} sym anim quiver.mp4", bitrate=12000)
    plt.show()


def update_quiver(num, Q, velocity, z):
    """updates the horizontal and vertical vector components by a
    fixed increment on each frame
    """

    U = velocity[num, :, :, z, 0]
    V = velocity[num, :, :, z, 1]

    Q.set_UVC(U, V)

    return Q


def plot_cost(t, error, order):
    #colour = ["green", "blue", "red", "black", "yellow"]
    colour = {}
    # x=[]
    # y=[]
    for o in sorted(set(order)):
        x = []
        for i, time in enumerate(t):
            if order[i] == o:
                print(float(time))
                x.append(float(time))

        y = []
        for i, err in enumerate(error):
            if order[i] == o:
                y.append(float(err))
        # plt.scatter(x, y, c=colour[int(int(o)/2)], label=f"{o}th order")
        # plt.scatter(x, y, c=np.random.rand(3,), label=f"{o}th order")

        if o not in colour:
            colour[o] = np.random.rand(3,)

        plt.scatter(x, y, c=colour[o], label=f"{o}th order")

    plt.ylim(bottom=0)
    plt.xlim(left=0)

    plt.title(
        "Integral of error against grid size for different orders of central difference scheme")
    plt.xlabel("Wall Time (s)")
    plt.ylabel("Error integral")
    plt.legend()
    # plt.xscale("log")
    # plt.yscale("log")
    plt.grid(True)

    plt.show()


def plot_order(error, order):
    plt.plot(order, error)

    plt.ylim(bottom=0)

    plt.title(
        "Integral of error against different orders of central difference scheme")
    plt.xlabel("Order")
    plt.ylabel("Error integral")
    # plt.xscale("log")
    # plt.yscale("log")
    plt.grid(True)

    plt.show()


def plot_cores(cores, t, runId):

    # for num, i in enumerate(runId):
    #     if i < 17:
    #         plt.scatter(cores[num], t[num], c="red")
    #     elif i < 32:
    #         plt.scatter(cores[num], t[num], c="blue")
    #     else:
    #         plt.scatter(cores[num], t[num], c="green")
    plt.scatter(cores, t)
    plt.ylim(bottom=0)
    plt.ylabel("Wall time (s)")
    plt.xlabel("Number of Threads")
    plt.show()


def plot_scatter():
    # Plot integral of error
    y = [0.1723, 0.1249, 0.07821, 0.01538]
    x = [32, 48, 64, 128]
    plt.scatter(x, y, c="red", label="4th order")

    y = [0.1837, 0.1290, 0.08187]
    x = [32, 48, 64]
    plt.scatter(x, y, c="blue", label="6th order")

    #plt.xlim(0, x[-1])
    plt.ylim(bottom=0)
    plt.xticks(x)
    plt.title(
        "Integral of error against grid size for 4th and 6th order central difference scheme")
    plt.xlabel("Grid size")
    plt.ylabel("Error integral")
    plt.legend()
    plt.show()

    # Plot max error
    y = [0.005048, 0.0040998, 0.00296, 0.0006431]
    x = [32, 48, 64, 128]
    plt.scatter(x, y, c="red", label="4th order")

    y = [0.005525, 0.004582, 0.003160]
    x = [32, 48, 64]
    plt.scatter(x, y, c="blue", label="6th order")

    #plt.xlim(0, x[-1])
    plt.ylim(bottom=0)
    plt.xticks(x)
    plt.title(
        "Max error against grid size for 4th and 6th order central difference scheme")
    plt.xlabel("Grid size")
    plt.ylabel("Max Error")
    plt.legend()
    plt.show()
