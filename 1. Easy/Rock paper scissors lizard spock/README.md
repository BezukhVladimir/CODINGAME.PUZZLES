# Rock paper scissors lizard spock
https://www.codingame.com/training/easy/rock-paper-scissors-lizard-spock/

## Goal
An international Rock Paper Scissors Lizard Spock tournament is organized, all players receive a number when they register.

Each player chooses a sign that he will keep throughout the tournament among: <br>
Rock (R) <br>
Paper (P) <br>
sCissors (C) <br>
Lizard (L) <br>
Spock (S)

Scissors cuts Paper <br>
Paper covers Rock <br>
Rock crushes Lizard <br>
Lizard poisons Spock <br>
Spock smashes Scissors <br>
Scissors decapitates Lizard <br>
Lizard eats Paper <br>
Paper disproves Spock <br>
Spock vaporizes Rock <br>
Rock crushes Scissors <br>
and in case of a tie, the player with the lowest number wins (it's scandalous but it's the rule).

## Input
Line 1: an integer N representing the number of participants in the competition <br>
Lines 2 to N+1: an integer NUMPLAYER indicating the player number (players have distinct numbers between 1 and N) followed by a letter 'R', 'P', 'C', 'L' or 'S' <br> indicating the chosen sign SIGNPLAYER

## Output
Line 1: the number of the winner <br>
Line 2: the list of its opponents separated by spaces

## Constraints
N is a 2^k value (2, 4, 8, 16, ..., 1024) <br>
2 ≤ N ≤ 1024

## Example
### Input
8 <br>
4 R <br>
1 P <br>
8 P <br>
3 R <br>
7 C <br>
5 S <br>
6 L <br>
2 L

### Output
2 <br>
6 5 1
