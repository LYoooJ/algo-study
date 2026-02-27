import sys
n = int(sys.stdin.readline().strip())
win_time = {1:0, 2:0}
score = {1:0, 2:0}
last_event = 0

for _ in range(n):
    line = sys.stdin.readline().split()
    team = int(line[0])
    time = line[1]
    
    m, s = map(int, time.split(':'))
    total_second = m * 60 + s
    
    if score[1] > score[2]:
        win_time[1] += (total_second - last_event)
    elif score[2] > score[1]:
        win_time[2] += (total_second - last_event)
    
    score[team] += 1
    
    last_event = total_second

game_end = 48 * 60

if score[1] > score[2]:
    win_time[1] += (game_end - last_event)
elif score[2] > score[1]:
    win_time[2] += (game_end - last_event)
    
for i in [1, 2]:
    m = win_time[i] // 60
    s = win_time[i] % 60
    
    print(f"{m:02d}:{s:02d}")