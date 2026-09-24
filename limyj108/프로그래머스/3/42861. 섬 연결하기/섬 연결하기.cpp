#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int find_parent(int x) {
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

void merge(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);
    
    if (pa < pb) parent[pb] = pa;
    else parent[pa] = pb;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, bridge_cnt = 0;
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), [] (const auto& a, const auto& b) {
        return a[2] < b[2];
    });
    
    for (vector<int>& edge : costs) {
        if (find_parent(edge[0]) == find_parent(edge[1])) continue;
        merge(edge[0], edge[1]);
        answer += edge[2];
        bridge_cnt++;
        if (bridge_cnt == n - 1) break;
    }
    return answer;
}