#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e4
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<vector<int>> adj(N + 1);
vector<int> ty(N + 1, 0);

void f(int node, int type) {
    ty[node] = type;
    for (const int& elt : adj[node]) {
        if (ty[elt] == 0) f(elt, 3 - type);
        else if (ty[elt] != 3 - type) {flag = false; return;}

        if (!flag) return;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int start, end;
    for (int i = 0; i < n; ++i) {
        cin >> m >> h;

        for (int i = 1; i <= m; ++i) adj[i].clear();
        ty.assign(m + 1, 0);
        
        for (int j = 0; j < h; ++j) {
            cin >> start >> end;
            adj[start].push_back(end);
            adj[end].push_back(start);
        }

        flag = true;
        for (int j = 1; j <= m; ++j) {
            if (ty[j] == 0) f(j, 1);
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}