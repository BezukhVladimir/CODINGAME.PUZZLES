import sys
import math

NUMBER = int(input())
result = 10000000
horses = []

for i in range(NUMBER):
    horses.append(int(input()))

horses.sort()

for i in range(1, NUMBER):
    result = min(result, horses[i] - horses[i - 1])

print(result)