#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans = -1;
vector<bool> visited;

void dfs(int k, int n, vector<vector<int>>& dungeons) {
    for (int i = 0; i < N; i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(k - dungeons[i][1], n + 1, dungeons);
            visited[i] = false;
        }
    }
    ans = max(ans, n);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();  
    visited.resize(N, false);
    dfs(k, 0, dungeons);
    return ans;
}