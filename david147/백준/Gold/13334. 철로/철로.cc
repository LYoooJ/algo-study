#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int h, o, d;
    vector<pair<int, int>> ho;
    for (int i = 0; i < n; ++i) {
        cin >> h >> o;
        ho.push_back({min(h, o), max(h, o)});
    }
    sort(all(ho), cmp);
    
    cin >> d;
    int maximum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cur;
    for (int i = 0; i < n; ++i) {
        if (ho[i].second - ho[i].first > d) continue;
        
        cur.push({ho[i].first, ho[i].second});
        while (cur.size() && cur.top().first < ho[i].second - d) cur.pop();

        maximum = max(maximum, (int) cur.size());
    }

    cout << maximum << '\n';

    return 0;
}