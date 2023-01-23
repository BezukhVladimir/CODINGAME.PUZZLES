import sys
import math

class town:
    def __init__(self, *townData):
        townData = townData[0].split()
        self.x, self.y = [int(i) for i in townData]
    
n = int(input())
select = town(input())
firstTown = select
result = 0
towns = []

for i in range(n - 1):
    towns.append(town(input()))
    
while len(towns):
    x0, y0 = select.x, select.y
    bestDistance = 10000
    
    for i in range(len(towns)):
        x1, y1 = towns[i].x, towns[i].y
        distance = ((abs(x0 - x1) ** 2 + abs(y0 - y1) ** 2) ** 0.5)
        
        if distance < bestDistance:
            bestDistance = distance
            select = towns[i]
            idx = i
    
    del towns[idx] 
    result += bestDistance

x0, y0 = select.x, select.y    
x1, y1 = firstTown.x, firstTown.y
result += ((abs(x0 - x1) ** 2 + abs(y0 - y1) ** 2) ** 0.5)
    
print(round(result))