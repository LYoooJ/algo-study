import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
k = int(input())
board = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(k):
    r, c = map(int, input().split())
    board[r][c] = 1

l = int(input())
times = {}
for _ in range(l):
    x, c = input().split()
    times[int(x)] = c

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

x, y = 1, 1
board[x][y] = 2
direction = 0
time = 0
snake = deque([(x, y)])

while True:
    time += 1
    nx = x + dx[direction]
    ny = y + dy[direction]

    if 1 <= nx <= n and 1 <= ny <= n and board[nx][ny] != 2:
        if board[nx][ny] == 0:
            tx, ty = snake.popleft()
            board[tx][ty] = 0
        
        board[nx][ny] = 2
        snake.append((nx, ny))
        x, y = nx, ny
        
        if time in times:
            if times[time] == 'L':
                direction = (direction - 1) % 4
            else:
                direction = (direction + 1) % 4
    else:
        break

print(time)