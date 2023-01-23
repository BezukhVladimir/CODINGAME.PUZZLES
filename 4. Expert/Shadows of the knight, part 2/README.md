# Shadows of the knight, part 2
https://www.codingame.com/training/expert/shadows-of-the-knight-episode-2/

## Goal
Due to the new heat cloak shielding the bombs, the device can no longer provide the direction of the bombs! It can only indicate whether you are getting closer or further away from the bombs.

## Rules
After each jump, the upgraded device will now provide you with the following information code: <br>
COLDER You are further away from the bombs than you were before jumping <br>
WARMER You are closer to the bombs than you were before jumping <br>
SAME You are at the same distance from the bombs as you were before jumping <br>
UNKNOWN The device cannot provide you with any information: only happens before the first jump

The Euclidean distance is used for the measurements of the distance to the bombs:

![image](https://user-images.githubusercontent.com/91319870/214097706-52f5a788-b16c-4f9f-bb89-1898b7be33f3.png)

As for the previous question your mission is to program the device so that it indicates the location of the next window you should jump to in order to reach the bombs' room as soon as possible.

Buildings are represented as a rectangular array of windows, the window in the top left corner of the building is at index (0,0).

Note: <br>
For some tests, the bombs' location may change from one execution to the other: the goal is to help you find the best algorithm in all cases.

The tests provided are similar to the validation tests used to compute the final score but remain different.

## Game Input
The program must first read the initialization data from standard input. Then, within an infinite loop, read the device data from the standard input and provide to the standard output the next movement instruction.

### Initialization input
Line 1 : 2 integers W H. The (W, H) couple represents the width and height of the building as a number of windows. <br>
Line 2 : 1 integer N, which represents the number of jumps you can make before the bombs go off. <br>
Line 3 : 2 integers X0 Y0, representing your starting position.

### Input for one game turn
A single line providing the device code: COLDER WARMER SAME or UNKNOWN

### Output for one game turn
A single line with 2 integers X Y separated by a space character. (X, Y) represents the location of the next window you should jump to. X represents the index along the horizontal axis, Y represents the index along the vertical axis. (0,0) is located in the top-left corner of the building.

### Constraints
1 ≤ W ≤ 10000 <br>
5 ≤ H ≤ 10000 <br>
2 ≤ N ≤ 100 <br>
0 ≤ X, X0 < W <br>
0 ≤ Y, Y0 < H <br>
Response time per turn ≤ 150ms

## Example
### Initialization input
10 10     Building has 100 windows (10x10) <br>
6         You have 6 jumps to find the bombs <br>
2 5       You start at position (2,5) <br>
No output expected

### Input for turn 1
UNKNOWN <br>
You have not jumped yet

### Output for turn 1
7 2 <br>
You jump to window (7,2)

### Input for turn 2
WARMER <br>
You get nearer the bombs

### Output for turn 2
7 6 <br>
You jump to window (7,6)

### Input for turn 3
SAME <br>
You are at the same distance from the bombs

### Output for turn 3
7 4 <br>
You jump to window (7,4) <br>
You found the hostages. You can defuse the bombs in time. You win!
