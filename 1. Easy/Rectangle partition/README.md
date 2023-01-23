# Rectangle partition
https://www.codingame.com/training/easy/rectangle-partition/

## Goal
There is a rectangle of given width w and height h, <br>

On the width side, you are given a list of measurements. <br>
On the height side, you are given another list of measurements. <br>

Draw perpendicular lines from the measurements to partition the rectangle into smaller rectangles.

In all sub-rectangles (include the combinations of smaller rectangles), how many of them are squares?

## Input
Line 1: Integers w h countX countY, separated by space <br>
Line 2: list of measurements on the width side, countX integers separated by space, sorted in asc order <br>
Line 3: list of measurements on the height side, countY integers separated by space, sorted in asc order

## Output
Line 1: the number of squares in sub-rectangles created by the added lines

## Constraints
1 ≤ w, h ≤ 20,000 <br>
1 ≤ number of measurements on each axis ≤ 500

## Example
### Input
10 5 2 1 <br>
2 5 <br>
3
### Output
4
