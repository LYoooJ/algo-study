import sys
import heapq

input = sys.stdin.readline

n = int(input())
max_heap = []
    
for _ in range(n):
    x = int(input())
        
    if x > 0:
        heapq.heappush(max_heap, -x)
    else:
        if not max_heap:
                print(0)
        else:
            print(-heapq.heappop(max_heap))
