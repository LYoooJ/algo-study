#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

ll EEA(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1; y = 0; return a;}

    ll xx, yy;
    ll gcd = EEA(b, a % b, xx, yy);

    x = yy;
    y = xx - (a / b) * yy;

    return gcd;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        ll k, c, x, y, gcd;
        cin >> k >> c;
        if ((gcd = EEA(k, c, x, y)) == 1) {
            while (x > -1) {y += (k / gcd); x -= (c / gcd);}
            if (y <= (ll) 1e9) cout << y << '\n';
            else cout << "IMPOSSIBLE\n";
        }
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}