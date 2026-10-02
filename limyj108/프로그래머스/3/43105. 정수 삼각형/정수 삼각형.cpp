#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    int N = triangle.size();
    
    for (int r = 1; r < N; r++) {
        for (int c = 0; c <= r; c++) {
            if (c == 0) triangle[r][c] += triangle[r - 1][c];
            else if (c == r) triangle[r][c] += triangle[r - 1][c - 1];
            else triangle[r][c] += triangle[r - 1][c - 1] > triangle[r - 1][c] ? triangle[r - 1][c - 1] : triangle[r - 1][c];
        }
    }
    
    for (int c = 0; c < N; c++) {
        answer = answer < triangle[N - 1][c] ? triangle[N - 1][c] : answer;
    }
    
    return answer;
}