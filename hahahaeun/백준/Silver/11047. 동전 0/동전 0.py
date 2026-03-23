import sys

input = sys.stdin.readline

n, k = map(int, input().split())

coin = [int(input()) for _ in range(n)]

coin.sort(reverse=True)

count_coin = 0
i = 0
while k > 0:
    if k // coin[i] != 0:
        count_coin +=  (k // coin[i])
        k -= (coin[i] * (k // coin[i]))
    i += 1

print(count_coin)