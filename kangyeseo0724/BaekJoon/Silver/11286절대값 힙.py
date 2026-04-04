import heapq
import sys

input = sys.stdin.read
data = input().split()

n = int(data[0])
heap = []

result = []
for i in range(1, n + 1):
    x = int(data[i])
    
    if x != 0:
        heapq.heappush(heap, (abs(x), x))
    else:
        if not heap:
            result.append(0)
        else:
            result.append(heapq.heappop(heap)[1])

print('\n'.join(map(str, result)))