#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 40
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> a, b;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n / 3; ++i) {
        a.push_back(n - i * 3);
        b.push_back(n - i * 3 - 1);
        b.push_back(n - i * 3 - 2);
    }

    if (n % 3 == 2) {a.push_back(2); b.push_back(1);}

    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); ++i) cout << a[i] << ' ';
    cout << '\n';
    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
    cout << '\n';
    
    return 0;
}