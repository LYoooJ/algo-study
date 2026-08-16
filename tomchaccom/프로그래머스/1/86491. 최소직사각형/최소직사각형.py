def solution(sizes):
    answer = 0
    # 회전의 영향을 줄이기 위해서 가로 세로 중 큰값을 가로, 작은 값을 세로로 분류 
    garo = []
    sero = []
    
    for w, h in sizes:
        if w >= h:
            garo.append(w)
            sero.append(h)
        else:
            garo.append(h)
            sero.append(w)
    
    answer = max(garo) * max(sero)
    return answer