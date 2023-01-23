import sys
import math

InputNumberHouses, InputNumberConnectionPairs = [int(i) for i in input().split()]
House1 = []
House2 = []
Cost = []
ResultListIndex = []
ResultListHouse1 = []
ResultListHouse2 = []
ResultListCost = []
for i in range(InputNumberConnectionPairs):
    House1_tmp, House2_tmp, CostTmp = [int(j) for j in input().split()]
    House1.append(House1_tmp)
    House2.append(House2_tmp)
    Cost.append(CostTmp)
Connect = [1]
PairsCount = 0
AllCost = 0
MinimumCost = 10000
MinimumIndex = None
while len(Connect) != InputNumberHouses:
    for i in range(InputNumberConnectionPairs):
        if (((House1[i] in Connect) ^ (House2[i] in Connect)) and (int(Cost[i]) < MinimumCost)):
            MinimumCost = Cost[i]
            MinimumIndex = i
    if House1[MinimumIndex] in Connect:
        Connect.append(House2[MinimumIndex])
        ResultListIndex.append(MinimumIndex)
        ResultListHouse1.append(House1[MinimumIndex])
        ResultListHouse2.append(House2[MinimumIndex])
        ResultListCost.append(Cost[MinimumIndex])
        PairsCount += 1
        AllCost += MinimumCost
    else:
        Connect.append(House1[MinimumIndex])
        ResultListIndex.append(MinimumIndex)
        ResultListHouse1.append(House1[MinimumIndex])
        ResultListHouse2.append(House2[MinimumIndex])
        ResultListCost.append(Cost[MinimumIndex])
        PairsCount += 1
        AllCost += MinimumCost
    MinimumCost = 10000
    MinimumIndex = None  
print(PairsCount, AllCost)
Result = []
for j in range(len(ResultListIndex)):
    Result.append((ResultListHouse1[j], ResultListHouse2[j], ResultListCost[j]))
Result.sort()
for j in range(len(ResultListIndex)):
    print(*Result[j])