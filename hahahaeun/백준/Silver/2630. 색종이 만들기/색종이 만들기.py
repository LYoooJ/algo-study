import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
grid = []

for _ in range(n):
    grid.append(list(map(int, input().split())))

def find_color(x, y, size):
    color = grid[y][x]
    
    for i in range(y, y+size):
        for j in range(x, x+size):
            if grid[i][j] != color:
                half = size // 2
                w1, b1 = find_color(x, y, half)
                w2, b2 = find_color(x, y+half, half)
                w3, b3 = find_color(x+half, y, half)
                w4, b4 = find_color(x+half, y+half, half)
                return (w1 + w2 + w3 + w4, b1 + b2 + b3 + b4)

    if color == 0:
        return (1, 0)
    else:
        return (0, 1)

w_count, b_count = find_color(0, 0, n)
print(w_count)
print(b_count)
