import sys
import heapq
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    k = int(input())
    min_h = []
    max_h = []
    visit = [False] * k

    for i in range(k):

        cmd, n = input().split()
        
        if cmd == 'I':
            heapq.heappush(min_h, (int(n), i))
            heapq.heappush(max_h, (-int(n), i))
            visit[i] = True

        elif cmd == 'D':
            if n == '1':
                while max_h and not visit[max_h[0][1]]:
                    heapq.heappop(max_h)
                if max_h:
                    _, idx = heapq.heappop(max_h)
                    visit[idx] = False
            else:
                while min_h and not visit[min_h[0][1]]:
                    heapq.heappop(min_h)
                if min_h:
                    _, idx = heapq.heappop(min_h)
                    visit[idx] = False
        
    while min_h and not visit[min_h[0][1]]:
        heapq.heappop(min_h)

    while max_h and not visit[max_h[0][1]]:
        heapq.heappop(max_h)

    if not min_h:
        print('EMPTY')
    else:
        print(-max_h[0][0], min_h[0][0])