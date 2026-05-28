#include <string>
#include <vector>

using namespace std;

pair<int, int> drc[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

bool is_valid(pair<int, int> p, int board_rows, int board_cols);

int solution(vector<vector<int>> board) {
    int answer = 0;
    int board_rows = board.size(), board_cols = board[0].size();
    
    for (int r = 0; r < board_rows; r++) {
        for (int c = 0; c < board_cols; c++) {
            bool is_safe = board[r][c] == 0;
            for (pair<int, int> d_ : drc) {
                pair<int, int> next = {r + d_.first, c + d_.second};
                if (is_valid(next, board_rows, board_cols) && board[next.first][next.second] == 1) {
                    is_safe = false;
                }
            }
            if (is_safe) {
                answer++;
            }
        }
    }
    return answer;
}

bool is_valid(pair<int, int> p, int board_rows, int board_cols) {
    return 0 <= p.first && p.first < board_rows && 0 <= p.second && p.second < board_cols;
}