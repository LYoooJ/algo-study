#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<vector<int>> adj(N + 1); 
vector<int> visited(N + 1, 0);
int idx;

void dfs(int node) {
    if (visited[node]) return;

    visited[node] = ++idx;
    for (const int& elt : adj[node]) dfs(elt);
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

    dfs(h);

    for (int i = 1; i <= n; ++i) cout << visited[i] << '\n';

    return 0;
}