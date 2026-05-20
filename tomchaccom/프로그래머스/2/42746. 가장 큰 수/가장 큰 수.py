
def solution(numbers):
    answer = list(map(str, numbers))
    
    answer.sort(key = lambda x : x * 3 , reverse = True)
    
    if answer[0] == "0":
        return "0"
    
    return "".join(answer)
    
    # 앞자리만 비교하고 있긴함. 
    


