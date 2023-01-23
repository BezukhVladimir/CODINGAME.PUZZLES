import sys
import math

w, h = [int(i) for i in input().split()]
input()
x, y = [int(i) for i in input().split()]

x0, y0, x1, y1 = 0, 0, w, h

while True:
    bomb = input()
    for c in bomb:
        if c == "U":
            y1 = y
        elif c == "D":
            y0 = y
        elif c == "R":
            x0 = x
        elif c == "L":
            x1 = x
    x = (x0 + x1) >> 1
    y = (y0 + y1) >> 1
    print(x, y)