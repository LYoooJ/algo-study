def solution(citations):
    answer = 0
    h = 1
    
    while True:
        
        ci = len([c for c in citations if c >= h])
        if h > ci:
            return h - 1 
        else:
            h += 1
        
    
    return h