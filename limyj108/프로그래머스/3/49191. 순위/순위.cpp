#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int bfs(int src, int n, vector<vector<int>>& adj) {
    int cnt = 0;
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(src); visited[src] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop(); cnt++;
        
        for (int nxt : adj[cur]) {
            if (!visited[nxt]) {
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }
    return cnt - 1;
}

int solution(int n, vector<vector<int>> results) {
    int ans = 0;
    vector<vector<int>> lose_to; vector<vector<int>> win_to;
    lose_to.resize(n + 1); win_to.resize(n + 1);
    
    for (vector<int>& result : results) {
        win_to[result[0]].push_back(result[1]);
        lose_to[result[1]].push_back(result[0]);
    }
    
    for (int i = 1; i <= n; i++) {
        int lose_cnt = bfs(i, n, lose_to), win_cnt = bfs(i, n, win_to);
        if (lose_cnt + win_cnt == n - 1) {
            ans++;
        }
    }
    
    return ans;
}