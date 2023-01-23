WIDTH, HEIGHT = [int(x) for x in input().split()]
    
ORIGINAL_TOP = list(input())
top = list(ORIGINAL_TOP)
    
for i in range(HEIGHT - 2):
    line = list(input())
    
    for j in range(0, WIDTH - 3, 3):
        if (line[j + 1] == '-'):
            top[j], top[j + 3] = top[j + 3], top[j]

result = {}; 
ORIGINAL_BOTTOM = list(input())
        
for i in range(int((WIDTH + 2) / 3)):
    result[top[i * 3]] = ORIGINAL_BOTTOM[i * 3]
        
for i in range(int((WIDTH + 2) / 3)): 
    print(ORIGINAL_TOP[i * 3] + result[ORIGINAL_TOP[i * 3]])