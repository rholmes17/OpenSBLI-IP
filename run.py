# Open two new terminals and run the simulation and the processing software

import os

os.system("gnome-terminal -e 'bash -c \"python3 process.py;bash\"'")

os.system("gnome-terminal -e 'bash -c \"python simulate.py;bash\"'")