#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k;
    cin >> k;

    vector<int> dp(10501, 10000);
    vector<int> unit = {100, 200, 500};
    dp[0] = 0;
    for (int i = 1; i <= k + 500; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i >= unit[j]) dp[i] = min(dp[i], dp[i - unit[j]] + 1);
        }
    }

    for (int i = k; i <= k + 500; ++i) {
        if (dp[i] < 10000) {
            cout << dp[i] << '\n';
            break;
        }
    }

    return 0;
}