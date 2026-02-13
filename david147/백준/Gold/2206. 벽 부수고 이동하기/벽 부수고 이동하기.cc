#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char map[1000][1000];
int cost[1000][1000][2], dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

void f() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cost[i][j][0] = cost[i][j][1] = INF;
        }
    }
    cost[0][0][0] = 1;

    int temp_x, temp_y, broken, x, y;
    while (!q.empty()) {
        temp_x = q.front().first.second;
        temp_y = q.front().first.first;
        broken = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            x = temp_x + dx[i];
            y = temp_y + dy[i];

            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            if (map[y][x] == '1') {
                if (broken == 0) {
                    if (cost[y][x][1] == INF) {
                        cost[y][x][1] = cost[temp_y][temp_x][0] + 1;
                        q.push({{y, x}, 1});
                    }
                }
            }
            else {
                if (cost[y][x][broken] == INF) {
                    cost[y][x][broken] = cost[temp_y][temp_x][broken] + 1;
                    q.push({{y, x}, broken});
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    f();

    minimum = min(cost[n - 1][m - 1][0], cost[n - 1][m - 1][1]);
    if (minimum == INF) cout << -1 << '\n';
    else cout << minimum << '\n';

    return 0;
}