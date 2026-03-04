#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<int> indegree(N+1, 0);

    for (int i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int next : adj[curr]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return 0;
}