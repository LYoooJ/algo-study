#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int simulate(int n, vector<vector<int>>& adj) {
    int cnt = 0;
    vector<bool> visited(n, false);
    queue<int> q; q.push(1); visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front(); cnt++; q.pop();
        for (int nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    return abs(n - 2 * cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 987654321;
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> adj(n + 1);
        for (int j = 0; j < wires.size(); j++) {
            if (j == i)
                continue;
            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }
        ans = min(ans, simulate(n, adj));
    }
    return ans;
}