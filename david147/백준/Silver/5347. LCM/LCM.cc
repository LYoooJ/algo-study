#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        cout << a * b / gcd(a, b) << '\n';
    }

    return 0;
}