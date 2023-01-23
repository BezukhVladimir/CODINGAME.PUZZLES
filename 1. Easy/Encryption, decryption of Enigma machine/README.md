# Encryption, decryption of Enigma machine
https://www.codingame.com/training/easy/encryptiondecryption-of-enigma-machine/

## Goal
During World War II, the Germans were using an encryption code called Enigma – which was basically an encryption machine that encrypted messages for transmission. The Enigma code went many years unbroken. Here's How the basic machine works:

First Caesar shift is applied using an incrementing number: <br>
If String is AAA and starting number is 4 then output will be EFG. <br>
A + 4 = E <br>
A + 4 + 1 = F <br>
A + 4 + 1 + 1 = G

Now map EFG to first ROTOR such as: <br>
ABCDEFGHIJKLMNOPQRSTUVWXYZ <br>
BDFHJLCPRTXVZNYEIWGAKMUSQO <br>
So EFG becomes JLC. Then it is passed through 2 more rotors to get the final value.

If the second ROTOR is AJDKSIRUXBLHWTMCQGZNPYFVOE, we apply the substitution step again thus: <br>
ABCDEFGHIJKLMNOPQRSTUVWXYZ <br>
AJDKSIRUXBLHWTMCQGZNPYFVOE <br>
So JLC becomes BHD.

If the third ROTOR is EKMFLGDQVZNTOWYHXUSPAIBRCJ, then the final substitution is: <br>
ABCDEFGHIJKLMNOPQRSTUVWXYZ <br>
EKMFLGDQVZNTOWYHXUSPAIBRCJ <br>
So BHD becomes KQF.

Final output is sent via Radio Transmitter.

## Input
Line 1: ENCODE or DECODE <br>
Line 2: Starting shift N <br>
Lines 3-5: <br>
BDFHJLCPRTXVZNYEIWGAKMUSQO ROTOR I <br>
AJDKSIRUXBLHWTMCQGZNPYFVOE ROTOR II <br>
EKMFLGDQVZNTOWYHXUSPAIBRCJ ROTOR III <br>
Line 6: Message to Encode or Decode

## Output
Encoded or Decoded String

## Constraints
0 ≤ N < 26 <br>
Message consists only of uppercase letters (A-Z) <br>
1 ≤ Message length < 50

## Example
### Input
ENCODE <br>
4 <br>
BDFHJLCPRTXVZNYEIWGAKMUSQO <br>
AJDKSIRUXBLHWTMCQGZNPYFVOE <br>
EKMFLGDQVZNTOWYHXUSPAIBRCJ <br>
AAA

### Output
KQF
