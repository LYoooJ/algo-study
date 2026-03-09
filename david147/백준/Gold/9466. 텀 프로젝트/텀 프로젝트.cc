#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<vector<int>> adj(N + 1);
int in_deg[N + 1];

void f() {
    ans = 0;

    queue<int> q;
    for (int i = 1; i <= m; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        ans++;
        if (--in_deg[adj[cur][0]] == 0) q.push(adj[cur][0]);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> m;

        for (int j = 1; j <= m; j++) {adj[j].clear(); in_deg[j] = 0;}
        

        for (int j = 1; j <= m; j++) {
            cin >> temp;
            adj[j].push_back(temp);
            in_deg[temp]++;
        }

        f();

        cout << ans << '\n';
    }

    return 0;
}