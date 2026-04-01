#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; ++i) cin >> arr[i];

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            arr.push_back(arr[i] + arr[j]);
        }
    }
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());

    queue<pair<int, int>> q;
    q.push({0, 0});

    int cur, cnt;
    vector<bool> visited(n + 1, false);
    while (!q.empty()) {
        cur = q.front().first;
        cnt = q.front().second;
        q.pop();

        // cout << cur << ' ' << cnt << '\n';

        if (cur == n) {cout << cnt << '\n'; return 0;}

        for (int i = 0; i < arr.size(); ++i) {
            if (cur + arr[i] > n) continue;

            if (!visited[cur + arr[i]]) {
                visited[cur + arr[i]] = true;
                q.push({cur + arr[i], cnt + 1});
            }
        }
    }
    
    cout << -1 << '\n';

    return 0;
}