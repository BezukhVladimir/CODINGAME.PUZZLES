import sys
import math

light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

while True:
    remaining_turns = int(input())
    while light_y != initial_ty and light_x != initial_tx:
        if initial_tx < light_x:
            if initial_ty < light_y:
                print("SE")
                initial_tx += 1
                initial_ty += 1
            else:
                print("NE")
                initial_tx += 1
                initial_ty -= 1
        else:
            if initial_ty < light_y:
                print("SW")
                initial_tx -= 1
                initial_ty += 1
            else:
                print("NW")
                initial_tx -= 1
                initial_ty -= 1
    while light_y != initial_ty:
        if initial_ty < light_y:
            print("S")
            initial_ty += 1
        else:
            print("N")
            initial_ty -= 1
    while light_x != initial_tx:
        if initial_tx < light_x:
            print("E")
            initial_tx += 1
        else:
            print("W")
            initial_tx -= 1