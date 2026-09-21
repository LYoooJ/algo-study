#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int max_dist = -1;
vector<int> dist;
vector<vector<int>> adj;
vector<bool> visited;

void bfs(int src) {
    queue<pair<int, int>> q;
    visited[src] = true;
    q.push({ src, 0 });
    
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        dist[cur.first] = cur.second;
        max_dist = max(max_dist, cur.second);
        
        for (int nxt : adj[cur.first]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push({ nxt, cur.second + 1 });
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int ans = 0;
    dist.resize(n + 1, 0);
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    
    for (vector<int>& e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    bfs(1);
    
    for (int i = 1; i <= n; i++) {
        if (max_dist == dist[i]) {
            ans++;
        }
    }
    return ans;
}