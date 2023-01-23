R = int(input())
robbers = [0] * R
for C, N in [list(map(int, input().split())) for _ in range(int(input()))]:
    robbers[robbers.index(min(robbers))] += 10**N * 5**(C - N)
print(max(robbers))