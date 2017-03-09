import fileinput
from sys import stdin

import math

if __name__ == "__main__":
    for line in fileinput.input():
        inline = line.strip()
        sep = inline.split(" ")
        sw = float(sep[1])/10
        q = float(sep[3])*sw/100
        d = 0.0
        if sep[5] == "R" or sep[5] == "H" or sep[5] == "D":
            d = int(sep[6])
        else:
            d = int(sep[5])
        d *= 2.54
        d += q*2
        all = math.pi * (d)
        sep.append(":")
        sep.append(round(all))
        for i in range(len(sep)):
            if i == 0:
                print(sep[i], end="")
            else:
                if sep[i] != ":":
                    print(" ",end="")
                print(str(sep[i]), end="")
        print("")