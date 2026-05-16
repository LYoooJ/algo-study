import collections

def solution(nums):
    answer = collections.Counter(nums)
    n = len(nums) / 2
    
    # 키의 갯수를 보고 판단. n = < keys n개 
    # n > keys keys개
    
    if n <= len(answer.keys()):
        return n
    else:
        return len(answer.keys())