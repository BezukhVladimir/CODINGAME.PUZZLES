# Prefix code
https://www.codingame.com/training/easy/prefix-code/

## Goal
Given a fixed set of characters, a code is a table that gives the encoding to use for each character.

A prefix code is a code with the prefix property, which is that there is no character with an encoding that is a prefix (initial segment) of the encoding of another character.


Your goal is to decode an encoded string using the given prefix code, or say that is not possible.

Example of encoding. <br>
Given the string "abracadabra" and the prefix code: <br>
a -> 1 <br>
b -> 001 <br>
c -> 011 <br>
d -> 010 <br>
r -> 000 <br>
The resulting encoding is: 10010001011101010010001

Thus, if your are given the code above and the input 10010001011101010010001, you should output the string "abracadabra".

With the same prefix code, if the input is 0000, then you should tell that there is an error at index 3. Indeed, the first three characters of this input can be decoded to give an 'r', but that leaves 0, which cannot be decoded.


External link: <br>
https://en.wikipedia.org/wiki/Prefix_code


What's next? <br>
Once you have solved this puzzle, you can continue the challenge by building efficient prefix codes: <br>
https://www.codingame.com/training/medium/huffman-code

## Input
Line 1: A single integer N representing the number of association in the prefix-code table. <br>
Next N lines: A binary code Bi and an integer Ci, which tells that the character with ASCII code Ci will be encoded by Bi. <br>
Next line: The binary code S of an encoded string.

## Output
- If it is not possible to decode the encoded string, print DECODE FAIL AT INDEX i with i the first index in the encoded string where the decoding fails (index starts from 0).
- Otherwise print the decoded string.

## Constraints
0 ≤ N, C ≤ 127 <br>
S and the binary codes Bi have a length less that or equal to 5000.

## Example
### Input
5 <br> 
1 97 <br>
001 98 <br>
000 114 <br>
011 99 <br>
010 100 <br>
10010001011101010010001

### Output
abracadabra
