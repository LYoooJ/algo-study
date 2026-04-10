#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string from, to;
        cin >> from >> to;

        vector<int> a_from, a_to;
        for (int i = 0; i < from.size(); ++i) {
            if (from[i] == 'a') a_from.push_back(i);
            if (to[i] == 'a') a_to.push_back(i);
        }

        int res = 0;
        for (int i = 0; i < a_from.size(); ++i) {
            res += abs(a_from[i] - a_to[i]);
        }

        cout << res << '\n';
    }
    
    return 0;
}