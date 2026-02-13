#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF INT_MAX

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
vector<pair<int, int>> graph[20000];
int dist[20000];

void f() {
    
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> h;
    int start, end, weight;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> weight;
        graph[start - 1].push_back({end - 1, weight});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n, INF);
    dist[h - 1] = 0;
    pq.push({0, h - 1});

    int temp_start, temp_cost;
    while (!pq.empty()) {
        temp_start = pq.top().second;
        temp_cost = pq.top().first;
        pq.pop();

        if (dist[temp_start] < temp_cost) continue;

        for (auto next : graph[temp_start]) {
            if (dist[next.first] > dist[temp_start] + next.second) {
                dist[next.first] = dist[temp_start] + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}