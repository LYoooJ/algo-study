import sys

#sys.stdin = open("input.txt", "rt")

def solution():
    N = int(sys.stdin.readline())
    times = list(map(int, sys.stdin.readline().split()))
    times.sort()
    
    tot = sum(time * (N - i) for i, time in enumerate(times)) # 반복 가능한(iterable) 객체를 입력받아, 각 요소의 인덱스(순번)와 값을 쌍(tuple)으로 반환하는 내장 함수
        
    sys.stdout.write(str(tot) + "\n")
        
if __name__ == "__main__":
    solution()