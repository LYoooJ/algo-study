import sys
n = int(sys.stdin.readline().strip())
np = int(sys.stdin.readline().strip())
dr = [1,0,-1,0]
dc = [0,1,0,-1]
r, c = 0, 0
start_num = n * n
target_r, target_c = 0, 0
d = 0
matrix = [[0] * n for _ in range(n)]
for i in range(start_num, 0, -1):
    matrix[r][c] = i
    
    if i == np:
        target_r, target_c = r + 1, c + 1
    
    if i == 1:
        break
    
    nr = r + dr[d]
    nc = c + dc[d]
    
    if nr < 0 or nr >= n or nc < 0 or nc >= n or matrix[nr][nc] != 0:
        d = (d + 1) % 4
        nr = r + dr[d]
        nc = c + dc[d]
        
    r, c = nr, nc
    
for row in matrix:
    print(*(row))
    
print(target_r, target_c)