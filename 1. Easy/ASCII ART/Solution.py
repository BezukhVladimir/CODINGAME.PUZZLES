import sys
import math

def printChar(line, char, row, width):
    begin = (ord(char) - ord('a')) * width
    end = begin + width
    print(row[line][begin:end], end = "")

width = int(input())
height = int(input())
text = input().lower()
row = []
for i in range(height):
    row.append(input())
    
for i in range(height):
    for j in text:
        if (ord('a') <= ord(j) <= ord('z')):
            printChar(i, j, row, width)
        else:
            printChar(i, chr(ord('z') + 1), row, width)
    print()