import sys
from collections import deque

input = sys.stdin.readline

m, n = map(int, input().split())

tomato = [list(map(int, input().split())) for _ in range(n)]
q = deque()
today = 0

di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]

for i in range(n):
    for j in range(m):
        if tomato[i][j] == 1:
            q.append((i,j))

while q:
    for _ in range(len(q)):
        ci, cj = q.popleft()
        for k in range(4):
            ni = ci + di[k]
            nj = cj + dj[k]

            if 0 <= ni < n and 0 <= nj < m:
                if tomato[ni][nj] == 0:
                    q.append((ni, nj))
                    tomato[ni][nj] += 1

    today += 1

for i in range(n):
    for j in range(m):
        if tomato[i][j] == 0:
            print(-1)
            exit()
if today == 0:
    print(0)

else:
    print(today-1)

                              
