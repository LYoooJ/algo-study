import sys
input = sys.stdin.readline

n = input().strip()


num = n.split('-')

total = 0

part1 = num[0].split('+')

for i in part1:
    total += int(i)

for i in num[1:]:
    numbers = i.split('+')

    for j in numbers:
        total -= int(j)

print(total)