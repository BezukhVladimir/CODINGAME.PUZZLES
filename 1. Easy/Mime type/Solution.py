import sys
import math

n = int(input())
q = int(input())  
wow = dict()
tmp = None

for i in range(n):
    A, B = input().split()
    wow[A.lower()] = B

for i in range(q):
    fname = input().lower().split('.')
    if len(fname) != 1:
        tmp = fname[-1]
    else:
        tmp = None
    if tmp in wow:
        print(wow[tmp])
    else:
        print("UNKNOWN")