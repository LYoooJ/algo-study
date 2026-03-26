#include <string>
#include <vector>
#include <queue>

using namespace std;

// 전역 변수 유지 (초기화 로직 추가 필수)
vector<vector<int>> graph(102, vector<int>(102, 0));
vector<vector<int>> visited(102, vector<int>(102, 0));
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y) {
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 1. 범위를 102로 확장 (가장 중요)
            if(nx < 0 || ny < 0 || nx >= 102 || ny >= 102) continue;
            if(!graph[nx][ny]) continue;
            if(visited[nx][ny]) continue;
            
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 2. 테스트 케이스 간 데이터 간섭 방지를 위한 초기화
    for(int i = 0; i < 102; i++) {
        fill(graph[i].begin(), graph[i].end(), 0);
        fill(visited[i].begin(), visited[i].end(), 0);
    }

    // 1. 모든 영역 채우기 (2배 확대)
    for(int i = 0; i < rectangle.size(); i++){
        int x1 = rectangle[i][0] * 2, y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2, y2 = rectangle[i][3] * 2;

        for(int j = x1; j <= x2; j++){
            for(int k = y1; k <= y2; k++){
                graph[j][k] = 1; 
            }
        }
    }

    // 2. 내부 파내기
    for(int i = 0; i < rectangle.size(); i++){
        int x1 = rectangle[i][0] * 2, y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2, y2 = rectangle[i][3] * 2;

        for(int j = x1 + 1; j < x2; j++){
            for(int k = y1 + 1; k < y2; k++){
                graph[j][k] = 0; 
            }
        }
    }

    bfs(characterX * 2, characterY * 2);
    
    // 시작점을 1로 잡았으므로 나누기 전에 -1을 할 필요는 없습니다. 
    // (visited 차이 자체가 이동 횟수가 되기 때문)
    return (visited[itemX * 2][itemY * 2] - 1) / 2;
}