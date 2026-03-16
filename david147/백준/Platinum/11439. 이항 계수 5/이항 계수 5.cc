#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 4e6
#define ll long long
// #define mod (ll 1e9 + 7)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long a, b, c, fac[N + 1] = { 1, };
vector<bool> is_prime(N + 1, true);
vector<ll> prime;

long long power(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    else if (exp == 1) return base % mod;
    
    long long temp = power(base, exp / 2, mod);
    if (exp % 2 == 0) return (temp * temp) % mod;
    else return (((temp * temp) % mod) * base) % mod;
}

ll legendre(ll n, ll p) {
    ll cnt = 0;
    while (n) {
        cnt += n / p;
        n /= p;
    }
    return cnt;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k, m;
    cin >> n >> k >> m;

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= n; j += i) is_prime[j] = false;
        }
    }

    long long res = 1, temp_exp;
    auto pos = upper_bound(prime.begin(), prime.end(), n);
    for (auto cur = prime.begin(); cur != pos; ++cur) {
        // cout << *cur << '\n';
        temp_exp = legendre(n, *cur) - legendre(k, *cur) - legendre(n - k, *cur);
        // cout << temp_exp << '\n';
        res *= power(*cur, temp_exp, m);
        res %= m;
    }

    cout << res << '\n';
    
    return 0;
}