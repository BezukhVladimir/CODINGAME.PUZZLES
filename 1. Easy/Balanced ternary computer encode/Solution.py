decimalNumber = int(input())

result = (decimalNumber == 0) * "0"
DIGIT_MASK = ((decimalNumber > 0) * "01T") + ((decimalNumber <= 0) * "0T1")

decimalNumber = abs(decimalNumber)

while (decimalNumber > 0):
    remainder = int(decimalNumber % 3)
    result += DIGIT_MASK[remainder]

    if (remainder == 2):
        decimalNumber += 3

    decimalNumber = int(decimalNumber / 3)

result = result[::-1]
print(result)