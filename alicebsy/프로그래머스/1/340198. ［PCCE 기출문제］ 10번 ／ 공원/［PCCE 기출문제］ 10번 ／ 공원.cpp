#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 해당 위치(r, c)에서 시작해서 size x size 크기의 빈 공간이 있는지 확인하는 함수
bool can_place(int r, int c, int size, const vector<vector<string>>& park) {
    int rows = park.size();
    int cols = park[0].size();
    
    // 돗자리가 공원 범위를 벗어나면 설치 불가
    if (r + size > rows || c + size > cols) {
        return false;
    }
    
    // size x size 영역 안에 사람이 있는지 검사
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (park[i][j] != "-1") {
                return false; // 사람이 있으면 설치 불가
            }
        }
    }
    return true; // 모두 빈 공간이면 설치 가능
}

int solution(vector<int> mats, vector<vector<string>> park) {
    // 1. 돗자리 크기를 큰 순서대로 정렬 (내림차순)
    sort(mats.begin(), mats.end(), greater<int>());
    
    int rows = park.size();
    int cols = park[0].size();
    
    // 2. 가장 큰 돗자리부터 차례대로 깔 수 있는지 확인
    for (int size : mats) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // 깔 수 있는 위치를 찾으면 바로 그 크기를 반환
                if (can_place(r, c, size, park)) {
                    return size;
                }
            }
        }
    }
    
    // 3. 어떤 돗자리도 깔 수 없다면 -1 반환
    return -1;
}