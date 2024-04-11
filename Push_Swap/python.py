import subprocess
import os
import time

BLUE = '\033[94m'
GREEN = '\033[92m'
RED = '\033[91m'
RESET = '\033[0m'

def usleep(mlsec):
    sec = mlsec / 1000000.0
    time.sleep(sec)

def put_arry():

    cmd_make = "make"
    cmd_cc_visualizer = "cc visualizer.c -o visualizer"
    os.system(cmd_make)
    os.system(cmd_cc_visualizer)
    char = "-48 -46 0 50 17 44 -2 -24 -25 27 -6 -23 10 -30 -7 26 -42 41 8 -13 46 39 42 -22 -14 -35 -44 -40 2 24 15 -36 30 34 37 38 -19 16 -50 -43 -45 7 13 -31 18 -27 -47 32 -34 22 23 25 19 -12 40 -21 -20 11 9 -11 -28 -32 47 -15 45 29 14 -5 20 -29 21 6 -10 28 33 -26 -41 -16 36 1 12 35 43 49 4 -1 5 31 -49 -9 -38 -17 3 -4 48 -39 -18 -8 -33 -3 -37"
    cmd = "./push_swap " + char

    result = os.popen(cmd).read().splitlines()
    
    cmd2 = "./visualizer " + ' '.join(result)
    os.system(cmd2)

def main():
    put_arry()

if __name__ == "__main__":
    main()
    