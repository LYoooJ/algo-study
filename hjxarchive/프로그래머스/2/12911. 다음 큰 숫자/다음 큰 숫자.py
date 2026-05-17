def solution(n):
    answer = 0
    temp = '0' + format(n, 'b')
    flag = 0
    start = 0
    for idx in range(len(temp)-1,-1,-1):
        cmp = temp[idx]
        if flag == 0:
            if cmp == '1':
                flag = 1
                start = idx
        else:
            if cmp == '0':
                break
                
    back = len(temp) - 2 - idx
    ones = temp[idx+2:].count('1')
    zeros = back - ones
    temp = temp[:idx] + "10" + "0"*zeros + "1"*ones
    answer = int(temp, 2)
    
        
        
    return answer
    