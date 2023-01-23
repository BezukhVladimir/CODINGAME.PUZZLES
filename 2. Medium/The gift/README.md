# The gift
https://www.codingame.com/training/medium/the-gift/

## Goal
The Pilipius want to offer a present to one of them. The thing is, they all have different budgets to invest in this present. Of course, their unique wish is to find the fairest method that will determine the maximum budget that each Pilipiu can afford. The Pilipius have been discussing this issue for days, and up until now, they have not managed to find a totally satisfactory solution.

The Doctor decides to give a helping hand by creating a program. His idea is to check if the Pilipius have enough money to buy the present, and if so, to calculate how much each Pilipiu should pay, according to their respective budget limit.

## Rules
The Doctor has in hand the list of maximum budgets for each Pilipiu. The Doctor's aim is to share the cost very precisely. To respect the Pilipius democratic values and to select the best solution, the Doctor decides that:
no Pilipiu can pay more than his maximum budget
the optimal solution is the one for which the highest contribution is minimal
if there are several optimal solutions, then the best solution is the one for which the highest second contribution is minimal, and so on and so forth...
Moreover, to facilitate the calculations, the Doctor wants each financial participation to be an integer of the local currency (nobody should give any cents).

Examples <br>
For example, the Pilipius wish to buy a gift that cost 100. The first Pilipiu has a budget of 3, the second has a budget of 45 and the third has a budget of 100.

In that case:

![image](https://user-images.githubusercontent.com/91319870/214091802-3622747b-9bde-43a1-ae84-463f35b98253.png)

Second example: they still wish to buy a gift that costs 100 but the second Pilipiu has a budget of 100 this time.

In that case:

![image](https://user-images.githubusercontent.com/91319870/214091879-803383c9-8004-4392-916a-66404b0917d8.png)

## Game Input
### Input
Line 1: the number N of participants <br>
Line 2: the price C of the gift <br>
N following lines: the list of budgets B of participants.

### Output
If it is possible to buy the present : N lines, each containing the contribution of a participant. The list is sorted in ascending order. <br>
Otherwise the word IMPOSSIBLE.

### Constraints
0 < N ≤ 2000 <br>
0 ≤ C ≤ 1000000000 <br>
0 ≤ B ≤ 1000000000

## Examples
### Input
3 <br>
100 <br>
20 <br>
20 <br>
40

### Output
IMPOSSIBLE

### Input
3 <br>
100 <br>
40 <br>
40 <br>
40

### Output
33 <br>
33 <br>
34

### Input
3 <br>
100 <br>
100 <br>
1 <br>
60

### Output
1 <br>
49 <br>
50
