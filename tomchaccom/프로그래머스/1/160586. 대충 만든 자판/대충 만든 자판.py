def solution(keymap, targets):
    answer = []
    
    # 각 문자의 최소 클릭 수 저장
    press_count = {}
    
    # keymap 순회
    for key in keymap:
        for idx, char in enumerate(key):
            # idx + 1 = 실제 누르는 횟수
            if char not in press_count:
                press_count[char] = idx + 1
            else:
                press_count[char] = min(press_count[char], idx + 1)
    
    # targets 계산
    for target in targets:
        total = 0
        possible = True
        
        for char in target:
            # 없는 문자면 -1
            if char not in press_count:
                possible = False
                break
            
            total += press_count[char]
        
        answer.append(total if possible else -1)
    
    return answer