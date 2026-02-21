import sys
n = int(sys.stdin.readline())

cows = {}
count = 0

for i in range(n):
    cow_id, position = map(int, sys.stdin.readline().split())
    
    if cow_id not in cows:
        cows[cow_id] = position
    
    else:
        if cows[cow_id] != position:
            count += 1
            cows[cow_id] = position

print(count)
