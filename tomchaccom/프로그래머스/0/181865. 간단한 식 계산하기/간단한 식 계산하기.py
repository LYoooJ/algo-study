def solution(binomial):
    answer = 0
    x ,oper, y = binomial.split(" ")
    
    x = int(x)
    y = int(y)
    
    if oper == "+":
        answer = x + y
    elif oper == "-":
        answer = x - y
    elif oper == "*":
        answer = x * y
    
    
    return answer