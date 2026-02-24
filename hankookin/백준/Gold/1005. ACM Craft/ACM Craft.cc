#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, W;
    cin >> N >> K;
    
    vector<int> buildTime(N + 1);
    vector<int> inDegree(N + 1, 0);
    vector<vector<int>> adj(N + 1);
    vector<int> resultTime(N + 1, 0);

    for (int i=1; i<=N; i++) {
        cin >> buildTime[i];
    }
    for (int i=0; i<K; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    cin >> W;

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            resultTime[i] = buildTime[i];
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            resultTime[next] = max(resultTime[next], resultTime[curr]+buildTime[next]);
            inDegree[next]--;

            if (inDegree[next] == 0) q.push(next);
        }
    }
    cout << resultTime[W] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

