#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, maximum = INT_MIN;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        cin >> m;
        pq.push(m);
    } 

    while (pq.size()) {
        m = pq.top();
        maximum = max(maximum, (int) (m * pq.size()));
        pq.pop();
    }

    cout << maximum << '\n';

    return 0;
}