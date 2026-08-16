def solution(answers):
    answer = []
    
    count = [0,0,0]
    
    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    for idx , ans in enumerate(answers):
        
        oidx = idx % len(one)
        tidx = idx % len(two)
        thidx = idx % len(three)
        
        if one[oidx] == ans:
            count[0] += 1
        if two[tidx] == ans:
            count[1] += 1
        if three[thidx] == ans:
            count[2] += 1
            
    mx = max(count)
    
    for i in range(len(count)):
        if count[i] == mx:
            answer.append(i+1)
    return answer