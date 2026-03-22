#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int idx;
vector<vector<int>> adj(N + 1);
vector<int> order(N + 1, 0);

void f(int node) {
    queue<int> q;
    q.push(node);

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (order[cur]) continue;
        order[cur] = ++idx;

        for (const int& elt : adj[cur]) {
            if (!order[elt]) q.push(elt);
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> h;

    int start, end;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }

    f(h);

    for (int i = 1; i <= n; ++i) cout << order[i] << '\n';

    return 0;
}