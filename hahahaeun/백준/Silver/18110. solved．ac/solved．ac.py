from collections import deque
import sys
input = sys.stdin.readline

q = deque()
n = int(input())

def myround(num):
    return int(num+0.5)

if n == 0:
    print(0)

else:
    ex = myround(n * 0.3 * 0.5)

    for _ in range(n):
        q.append(int(input())) 

    people = deque(sorted(q))

    for i in range(ex):
        people.pop()
        people.popleft()

    print(myround(sum(people)/len(people)))
    
