#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> graph; // 인접 그래프 이지만 거리도 같이 저장 
vector<int> visited;
int mx = -1;
int far_node;

void dfs(int node, int dist){
    visited[node] = 1;

    if(dist > mx){
        far_node = node;
        mx = dist;
    }
    for(auto &next : graph[node]){
        if(!visited[next.first]){
            dfs(next.first, dist + next.second);
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ;
    cin >> n;
    graph = vector<vector<pair<int,int>>>(n+1);
    visited = vector<int>(n+1, 0);
    for(int i = 0; i < n; i++){

        int start;

        cin >> start;

        while(1){
            int node,dist;
            cin >> node;

            if(node == -1){
                break;
            }
            cin >> dist;

            graph[start].push_back({node,dist});

        }
    }
    dfs(1,0);

    visited = vector<int> (n+1,0);
    mx = -1;
    dfs(far_node, 0);

    cout << mx;
}