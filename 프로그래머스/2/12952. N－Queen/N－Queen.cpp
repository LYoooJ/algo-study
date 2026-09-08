#include <string>
#include <vector>

using namespace std;

vector<int> board;
int answer = 0;

bool is_possible(int r, int c);
void dfs(int r, int n);

int solution(int n) {
    board.resize(n, 0);
    dfs(0, n);
    return answer;
}

void dfs(int r, int n) {
    for (int c = 0; c < n; c++) {
        if (is_possible(r, c)) {
            if (r == n - 1) {
                answer++;
            }
            board[r] = c;
            dfs(r + 1, n);
        }
    }
}

bool is_possible(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (board[i] == c)
            return false;
    }
    
    for (int i = 0; i < r; i++) {
        if ((r - i) == abs(board[i] - c)) {
            return false;
        }
    }
    return true;
}