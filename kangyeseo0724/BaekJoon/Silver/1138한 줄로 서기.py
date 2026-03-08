import sys
n = int(sys.stdin.readline().strip())

height = list(map(int, sys.stdin.readline().split()))
order = [0] * n

for i in range(n):
    count = height[i]
    
    for j in range(n):
        if count == 0 and order[j] == 0:
            order[j] = i + 1
            break
        elif order[j] == 0:
            count -= 1

print(*(order))
    
    