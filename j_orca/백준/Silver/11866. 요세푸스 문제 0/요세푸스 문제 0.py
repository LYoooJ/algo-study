import sys
from collections import deque

# sys.stdin = open("input.txt", "rt")

N, K = map(int, sys.stdin.readline().split())
queue = deque(range(1,N+1)) #deque(list(range(1, N+1)))에서 안쪽에 list()로 한 번 감쌀 필요가 없습니다. range 자체도 반복 가능한(iterable) 객체

def solution():
  answer_list = [] #answer_list = list()도 훌륭하지만, 파이썬에서는 answer_list = [] 리터럴 문법을 사용하는 것이 미세하게 더 빠르고 파이썬다운(Pythonic) 컨벤션(PEP 8)으로 여겨짐
  for i in range(N):
    for j in range(K-1):
      queue.append(queue.popleft())
    answer_list.append(str(queue.popleft())) # 파이썬은 강타입(Strong Type) 언어라서 정수 배열에 .join()을 쓰면 자비 없이 TypeError
       
  print(f"<{', '.join(answer_list)}>") #바깥에 쌍따옴표(")를 썼다면 안쪽에는 홑따옴표(')를 써야 합니다.

if __name__ == "__main__":
    solution()