#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long div_sum[1000001], acc[1000001];

void f() {
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) div_sum[j] += i;
    }
    
    acc[1] = div_sum[1];
    for (int i = 2; i <= 1000000; i++) acc[i] = acc[i - 1] + div_sum[i];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << acc[m] << '\n';
    }

    return 0;
}