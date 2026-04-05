def solution(s):
    l = 0
    for c in s:
        if l < 0:
            return False
        if c == '(':
            l += 1
        else:
            l -= 1
    
    if l != 0:
        return False
    else:
        return True