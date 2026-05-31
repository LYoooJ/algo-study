def solution(my_string, n):
    answer = ''
    idx = -n
    
    
    for i in range(n):
        answer += my_string[idx]
        idx+=1
    
    return answer