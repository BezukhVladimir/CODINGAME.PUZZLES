import sys
import math

message = input()
count = 0
check = None
binary = ''

for i in message:
    tmp = bin(ord(i))[2:]
    while len(tmp) < 7:
        tmp = '0' + tmp
    binary += tmp 
    
for j in binary:
    if j != check:
        print('0' * count, end = '')
        if count:
            print(' ', end = '')
        if j == '0':
            print('00', end = ' ')
        else:
            print('0', end = ' ')
        count = 1
    else:
        count += 1
    check = j
    
print('0' * count, end = '')