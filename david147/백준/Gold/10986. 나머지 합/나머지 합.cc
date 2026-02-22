#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int acc[1000001];
long long r[1000];

void f() {
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        acc[i + 1] = (acc[i] + cur % m) % m;
        r[acc[i + 1]]++;
    }

    long long ans = 0;
    ans += r[0] + (r[0] * (r[0] - 1)) / 2;
    for (int i = 1; i < m; i++) {
        ans += (r[i] * (r[i] - 1)) / 2;
    }

    cout << ans << '\n';

    return 0;
}