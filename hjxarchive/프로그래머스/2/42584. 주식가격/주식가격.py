def solution(prices):
    answer = [0 for _ in range(len(prices))]
    for cnt in range(len(prices)):
        temp = prices[cnt]
        for i in range(cnt+1, len(prices)):
            if temp > prices[i]:
                answer[cnt] = i - cnt 
                break
        if answer[cnt] == 0:
            answer[cnt] = len(prices) - cnt - 1
    return answer