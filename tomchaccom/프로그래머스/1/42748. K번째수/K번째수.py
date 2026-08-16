def solution(array, commands):
    answer = []
    for start, end, k in commands:
        sl = array[start-1 : end]
        sl.sort()
        
        answer.append(sl[k-1])
    
    return answer