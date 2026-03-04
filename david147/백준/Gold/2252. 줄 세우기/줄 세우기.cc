#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 32e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<vector<int>> adj(N + 1);
vector<int> in_deg(N + 1, 0), res;

void f() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) q.push(i);
    }

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (auto temp : adj[cur]) {
            if (--in_deg[temp] == 0) q.push(temp);
        }

        res.push_back(cur);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    int start, end;
    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        adj[start].push_back(end);
        in_deg[end]++;
    }

    f();

    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    cout << '\n';

    return 0;
}