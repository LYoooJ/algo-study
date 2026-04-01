#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t; 
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> board(n + 2, vector<char>(m + 2));
        vector<bool> keys(26, false);
        vector<pair<int, int>> start;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> board[i][j];
            }
        }
        for (int i = 0; i < n + 2; ++i) board[i][0] = board[i][m + 1] = '.';
        for (int i = 0; i < m + 2; ++i) board[0][i] = board[n + 1][i] = '.';
        
        string key;
        cin >> key;
        if (key[0] != '0') for (int i = 0; i < key.size(); ++i) keys[key[i] - 'a'] = true;

        queue<pair<int, int>> door[26];
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
        visited[0][0] = true;
        int cy, cx, res = 0;
        while (!q.empty()) {
            cy = q.front().first, cx = q.front().second;
            q.pop();

            char cur = board[cy][cx];
            if (cur >= 'a' && cur <= 'z') {
                keys[cur - 'a'] = true;

                while (!door[cur - 'a'].empty()) {
                    q.push(door[cur - 'a'].front());
                    door[cur - 'a'].pop();
                }
                board[cy][cx] = '.';
                q.push({cy, cx});
            }
            else if (cur == '.' || (cur >= 'A' && cur <= 'Z' && keys[cur - 'A']) || cur == '$') {
                if (cur == '$') res += 1;

                for (int i = 0; i < 4; ++i) {
                    int ny = cy + dy[i], nx = cx + dx[i];

                    if (ny < 0 || ny >= n + 2 || nx < 0 || nx >= m + 2) continue;

                    if (!visited[ny][nx] && board[ny][nx] != '*') {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
            else if (cur >= 'A' && cur <= 'Z' && !keys[cur - 'A']) door[cur - 'A'].push({cy, cx});
        }
        cout << res << '\n';   
    }

    return 0;
}