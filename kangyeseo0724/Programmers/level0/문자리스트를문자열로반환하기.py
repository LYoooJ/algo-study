def solution(arr):
    answer = ''
    for i in range (len(arr)):
        answer += arr[i]
    return answer

arr = input()
print(solution(arr))