from functools import cmp_to_key

def compare(a,b):
    if a + b > b + a:
        return -1
    elif a + b < b + a:
        return 1
    else:
        return 0

def solution(numbers):
    answer = list(map(str, numbers))
    
    result = sorted(answer, key = cmp_to_key(compare))
    
    if result[0] == "0":
        return "0"
    
    return "".join(result)

