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
        int n;
        cin >> n;

        n %= 28;
        if (n > 15) n = 30 - n;
        else if (n == 0) n = 2;

        for (int i = 3; i >= 0; --i) {
            if (n & (1 << i)) cout << "딸기";
            else cout << "V";
        }

        cout << '\n';
    }

    return 0;
}