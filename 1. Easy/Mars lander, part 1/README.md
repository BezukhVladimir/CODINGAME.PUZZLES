# Mars lander, part 1
https://www.codingame.com/training/easy/mars-lander-episode-1/

## Goal
The goal for your program is to safely land the "Mars Lander" shuttle, the landing ship which contains the Opportunity rover. Mars Lander is guided by a program, and right now the failure rate for landing on the NASA simulator is unacceptable.

Note that it may look like a difficult problem, but in reality the problem is easy to solve. This puzzle is the first level among three, therefore, we need to present you some controls you won't need in order to complete this first level.

## Rules
Built as a game, the simulator puts Mars Lander on a limited zone of Mars sky.

![image](https://user-images.githubusercontent.com/91319870/214063934-1944cad8-6308-4ab4-b191-4910f4cea6af.png)

The zone is 7000m wide and 3000m high.

For this level, Mars Lander is above the landing zone, in vertical position, with no initial speed.

There is a unique area of flat ground on the surface of Mars, which is at least 1000 meters wide.

Every second, depending on the current flight parameters (location, speed, fuel ...), the program must provide the new desired tilt angle and thrust power of Mars Lander:

![image](https://user-images.githubusercontent.com/91319870/214064110-78d1dbf9-43ad-435b-b43a-9af951b2a353.png)

Angle goes from -90° to 90°. <br>
Thrust power goes from 0 to 4 .

For this level, you only need to control the thrust power: the tilt angle should be 0.The game simulates a free fall without atmosphere. Gravity on Mars is 3.711 m/s² . For a thrust power of X, a push force equivalent to X m/s² is generated and X liters of fuel are consumed. As such, a thrust power of 4 in an almost vertical position is needed to compensate for the gravity on Mars.

For a landing to be successful, the ship must: <br>
land on flat ground <br>
land in a vertical position (tilt angle = 0°) <br>
vertical speed must be limited (≤ 40m/s in absolute value) <br>
horizontal speed must be limited (≤ 20m/s in absolute value)

Remember that this puzzle was simplified: <br>
the landing zone is just below the shuttle. You can therefore ignore rotation and always output 0 as the target angle. <br>
you don't need to store the coordinates of the surface of Mars to succeed. <br>
you only need your vertical landing speed to be between 0 and 40m/s – your horizontal speed being nil. <br>
As the shuttle falls, the vertical speed is negative. As the shuttle flies upward, the vertical speed is positive.

For this first level, Mars Lander will go through a single test.

Tests and validators are only slightly different. A program that passes a given test will pass the corresponding validator without any problem.

## Input
The program must first read the initialization data from standard input. Then, within an infinite loop, the program must read the data from the standard input related to Mars Lander's current state and provide to the standard output the instructions to move Mars Lander.

### Initialization input
Line 1: the number surfaceN of points used to draw the surface of Mars. <br>
Next surfaceN lines: a couple of integers landX landY providing the coordinates of a ground point. By linking all the points together in a sequential fashion, you form the surface of Mars which is composed of several segments. For the first point, landX = 0 and for the last point, landX = 6999

### Input for one game turn
A single line with 7 integers: X Y hSpeed vSpeed fuel rotate power <br>
X,Y are the coordinates of Mars Lander (in meters). <br>
hSpeed and vSpeed are the horizontal and vertical speed of Mars Lander (in m/s). These can be negative depending on the direction of Mars Lander. <br>
fuel is the remaining quantity of fuel in liters. When there is no more fuel, the power of thrusters falls to zero. <br>
rotate is the angle of rotation of Mars Lander expressed in degrees. <br>
power is the thrust power of the landing ship.

### Output for one game turn
A single line with 2 integers: rotate power: <br>
rotate is the desired rotation angle for Mars Lander. Please note that for each turn the actual value of the angle is limited to the value of the previous turn +/- 15°. <br>
power is the desired thrust power. 0 = off. 4 = maximum power. Please note that for each turn the value of the actual power is limited to the value of the previous turn +/- 1.

## Constraints
2 ≤ surfaceN < 30 <br>
0 ≤ X < 7000 <br>
0 ≤ Y < 3000 <br>
-500 < hSpeed, vSpeed < 500 <br>
0 ≤ fuel ≤ 2000 <br>
-90 ≤ rotate ≤ 90 <br>
0 ≤ power ≤ 4 <br>
Response time per turn ≤ 100ms

## Example
### Initialization input
6         (surfaceN) Surface made of 6 points <br>
0 1500    (landX landY) <br>
1000 2000	(landX landY) <br>
2000 500	(landX landY) Start of flat ground <br>
3500 500	(landX landY) End of flat ground <br>
5000 1500	(landX landY) <br>
6999 1000	(landX landY) <br>
No output expected <br>
You can ignore this but you need to read the values.

### Input for turn 1
2500 2500 0 0 500 0 0 	(X Y hSpeed vSpeed fuel rotate power)

### Output for turn 1
0 3

### Input for turn 2
2500 2499 0 -3 499 0 1 	(X Y hSpeed vSpeed fuel rotate power)

### Output for turn 2
0 3

### Input for turn 3
2500 2495 0 -4 497 0 2 	(X Y hSpeed vSpeed fuel rotate power)

### Output for turn 3
0 2
