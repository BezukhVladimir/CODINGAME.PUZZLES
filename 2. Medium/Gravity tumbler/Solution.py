import sys
import math

width, height = [int(i) for i in input().split()]
count = int(input())

result = [[0] * width for i in range(height)]


for i in range(height):
    raster = input()
    dots = ""
    hashes = ""
    for c in raster:
        if "." in c:
            dots += "."
        else:
            hashes += "#"
    if (count % 2) == 0:
        print(dots + hashes)
    else:
        string = dots + hashes
        for j in range(width):
            result[i][j] = string[j]

if count % 2:
    for i in range(width):
        for j in range(height):
            print(result[j][i], end = "")
        print()