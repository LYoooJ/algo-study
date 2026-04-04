import sys
from itertools import combinations

expression = sys.stdin.readline().strip()
stack = []
pairs = []

for i, char in enumerate(expression):
    if char == '(':
        stack.append(i)
    elif char == ')':
        pairs.append((stack.pop(), i))

results = set()

for i in range(1, len(pairs) + 1):
    for comb in combinations(pairs, i):
        to_remove = set()
        for p in comb:
            to_remove.add(p[0])
            to_remove.add(p[1])
        
        temp = ""
        for idx, char in enumerate(expression):
            if idx not in to_remove:
                temp += char
        results.add(temp)

for res in sorted(list(results)):
    print(res)