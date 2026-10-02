#include <string>
#include <iostream>
#include <vector>
#define DIV 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<bool>> board(n, vector<bool>(m, false));
    vector<vector<int>> DP(n, vector<int>(m, 0));
    for (vector<int> puddle : puddles) {
        board[puddle[1] - 1][puddle[0] - 1] = true;
    }
    
    for (int r = 0; r < n; r++) {
        if (board[r][0]) break;
        DP[r][0] = 1;
    }
    for (int c = 0; c < m; c++) {
        if (board[0][c]) break;
        DP[0][c] = 1;
    }
    
    for (int r = 1; r < n; r++) {
        for (int c = 1; c < m; c++) {
            if (board[r][c]) continue;
            DP[r][c] = (DP[r - 1][c] + DP[r][c - 1]) % DIV;
        }
    }
    return DP[n - 1][m - 1];
}
