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

    for (int i = 1; i <= t; ++i) {
        int n, m;
        cin >> n >> m;

        if (m < n - 1 || m >= n * (n + 1) / 2) {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
            continue;
        }

        bool flag = false;
        int left = 0, right = n - 1;
        vector<int> arr(n);
        for (int j = 0; j < n; ++j) arr[j] = j + 1;

        while (left < right) {
            if (m >= 2 * (right - left)) {
                flag = !flag;
                reverse(arr.begin() + left, arr.begin() + right + 1);
                m -= right - left + 1;
            }
            else --m;

            if (flag) --right;
            else ++left;
        }

        cout << "Case #" << i << ": ";
        for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
        cout << '\n';
    }

    return 0;
}