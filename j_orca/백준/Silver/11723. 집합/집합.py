import sys

if __name__ == "__main__":
  
  #sys.stdin = open("input.txt", "rt")

  N = int(sys.stdin.readline())
  S = set()
  full_Set = set(str(i) for i in range(1, 21))
  for _ in range(N):
    inst = sys.stdin.readline().split() 
    if inst[0] == 'add':
      S.add(inst[1])
    elif inst[0] == 'remove':
      S.discard(inst[1])
    elif inst[0] == 'check':
      sys.stdout.write('1\n' if inst[1] in S else '0\n')
    elif inst[0] == 'toggle':
      S.remove(inst[1]) if inst[1] in S else S.add(inst[1])
    elif inst[0] == 'all':
      S  = full_Set.copy()
    elif inst[0] == 'empty':
      S.clear()