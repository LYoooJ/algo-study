#include <string>
#include <vector>

using namespace std;

void dfs(int r, vector<int>& visited, vector<vector<int>>& computers);

void bfs(int src, vector<bool>& visited, vector<vector<int>> computers) {
    int N = computers.size();
    vector<int> q;
    int head = 0; q.push_back(src); visited[src] = true;
    
    while (head < q.size()) {
        int cur = q[head];
        head++;
        
        for (int nxt = 0; nxt < N; nxt++) {
            if (!visited[nxt] && computers[cur][nxt]) {
                visited[nxt] = true;
                q.push_back(nxt);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, N = computers.size();
    vector<bool> visited (N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            bfs(i, visited, computers);
            answer++;
        }
    }
    return answer;
}