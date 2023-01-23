import sys
import math

r_1 = int(input())
r_2 = int(input())

while r_1 != r_2:
    str_r_1 = str(r_1)
    str_r_2 = str(r_2)
    if r_1 < r_2:
        for i in str_r_1:
            r_1 += int(i)
    else:
        for i in str_r_2:
            r_2 += int(i)
            
print(r_1)