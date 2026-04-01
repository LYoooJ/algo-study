#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
#define is_range(n, r) ((n >= 0) && (n < r))

int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    int ry, rx, by, bx, hy, hx;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {rx = j; ry = i; board[ry][rx] = '.';}
            else if (board[i][j] == 'B') {bx = j; by = i; board[by][bx] = '.';}
        }
    }

    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
    q.push({{{ry, rx}, {by, bx}}, 0});

    bool visited[10][10][10][10];
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i2 = 0; i2 < m; ++i2) {
            for (int i3 = 0; i3 < n; ++i3) {
                for (int i4 = 0; i4 < m; ++i4) {
                    visited[i1][i2][i3][i4] = false;
                }
            }
        }
    }
    visited[ry][rx][by][bx] = true;

    int cry, crx, cby, cbx, cnt;
    while (!q.empty()) {
        cry = q.front().first.first.first, crx = q.front().first.first.second;
        cby = q.front().first.second.first, cbx = q.front().first.second.second;
        cnt = q.front().second;
        q.pop();

        // cout << cry << ' ' << crx << ' ' << cby << ' ' << cbx << ' ' << cnt << '\n';

        if (cnt > 10) continue;
        if (board[cry][crx] == 'O') {cout << cnt << '\n'; return 0;}

        for (int i = 0; i < 4; ++i) {
            int nry = cry, nrx = crx, nby = cby, nbx = cbx, r_move = 0, b_move = 0;
            
            while (is_range(nry + dy[i], n) && is_range(nrx + dx[i], m) && board[nry + dy[i]][nrx + dx[i]] != '#' && board[nry][nrx] != 'O') {
                nry += dy[i];
                nrx += dx[i];
                ++r_move;
            }
            while (is_range(nby + dy[i], n) && is_range(nbx + dx[i], m) && board[nby + dy[i]][nbx + dx[i]] != '#' && board[nby][nbx] != 'O') {
                nby += dy[i];
                nbx += dx[i];
                ++b_move;
            }

            if ((nry == nby && nrx == nbx) && board[nry][nrx] != 'O') {
                if (b_move > r_move) {nby -= dy[i]; nbx -= dx[i];}
                else {nry -= dy[i]; nrx -= dx[i];}
            }

            if (!visited[nry][nrx][nby][nbx] && board[nby][nbx] != 'O') {
                visited[nry][nrx][nby][nbx] = true;
                q.push({{{nry, nrx}, {nby, nbx}}, cnt + 1});
            }
        }
    }   

    cout << -1 << '\n';

    return 0;
}