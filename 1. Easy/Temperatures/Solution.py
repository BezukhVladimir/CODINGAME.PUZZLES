import sys
import math

n = int(input())
max_negative = -274
min_positive = 5527 # the number of temperatures to analyse

for i in input().split():
    t = int(i)
    if t < 0 and t > max_negative:
        max_negative = t
    if t > 0 and t < min_positive:
        min_positive = t

if max_negative == -274 and min_positive == 5527:
    print("0")
elif max_negative == -274 and min_positive != 5527:
    print(min_positive)
elif abs(max_negative) < min_positive:
    print(max_negative)
else:
    print(min_positive)