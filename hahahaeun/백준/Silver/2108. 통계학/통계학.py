import sys
input = sys.stdin.readline

n = int(input())
num = []

for _ in range(n):
    x = int(input())
    num.append(x)
num.sort()
print(round(sum(num)/n))
print(num[n//2])

counts = {}

for i in num:
    if i in counts:
        counts[i] += 1
    else:
        counts[i] = 1

max_count = max(counts.values())
goal = []
for k, v in counts.items():
    if v == max_count:
        goal.append(k)
goal.sort()
if len(goal) > 1:
    print(goal[1])
else:
    print(goal[0])



print(max(num)-min(num))



