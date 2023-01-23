SIZE = int(input())

for i in range(SIZE):
    print(((i == 0) * '.') + ((2 * (SIZE - 1) - i + (i > 0)) * " ") + ((2 * i + 1) * "*"))
        
for i in range(SIZE):
    print(((SIZE - 1 - i) * " ") + ((2 * i + 1) * "*") + ((2 * (SIZE - i) - 1) * " ") + ((2 * i + 1) * "*"))