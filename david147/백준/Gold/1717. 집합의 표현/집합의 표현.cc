#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int parent[N + 1], rnk[N + 1];

int find(int node) {
    if (node == parent[node]) return node;
    else {
        parent[node] = find(parent[node]);
        return parent[node];
    }
}

void merge(int node1, int node2) {
    int r1 = find(node1), r2 = find(node2);
    if (r1 == r2) return;
    
    if (rnk[r1] > rnk[r2]) parent[r2] = r1;
    else {
        parent[r1] = r2;
        if (rnk[r1] == rnk[r2]) rnk[r2]++;
    }
}

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rnk[i] = 1;
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) merge(b, c);
        else if (a == 1) {
            if (find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}