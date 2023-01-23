# Telephone numbers
https://www.codingame.com/training/medium/telephone-numbers/

## Goal
By joining the iDroid smartphone development team, you have been given the responsibility of developing the contact manager. Obviously, what you were not told is that there are strong technical constraints for iDroid: the system doesn’t have much memory and the processor is as fast as a Cyrix from the 90s...

In the specifications, there are two points in particular that catch your attention:

1 Intelligent Assistance for entering numbers
The numbers corresponding to the first digits entered will be displayed to the user almost instantly.

![image](https://user-images.githubusercontent.com/91319870/214091084-70eccd89-b9cc-4272-afaf-ae7c4946dc07.png)

2 Number storage optimization
First digits which are common to the numbers should not be duplicated in the memory.

Fortunately, the specifications also have this little chart to guide you in the implementation:

![image](https://user-images.githubusercontent.com/91319870/214091140-2ff60525-b044-443a-9fb3-de0c6ef9c717.png)

Your task is to write a program that displays the number of items (which are numbers) required to store a list of telephone numbers with the structure presented above.

## Game Input
### Input
Line 1: The number N of telephone numbers. <br>
N following lines: Each line contains a phone number, with a maximum length L. Telephone numbers consist of only the digits 0 to 9 included, without any spaces.

### Output
The number of elements (referencing a number) stored in the structure.

### Constraints
0 ≤ N ≤ 10000 <br>
2 ≤ L ≤ 20

## Examples
### Input
1 <br>
0467123456

### Output
10

### Input
2 <br>
0123456789 <br>
1123456789

### Output
20

### Input
2 <br>
0123456789 <br>
0123

### Output
10

### Input
5 <br>
0412578440 <br>
0412199803 <br>
0468892011 <br>
112 <br>
15

### Output
28
