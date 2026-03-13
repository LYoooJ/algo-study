#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[N];
deque<int> card;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int i = 1; i <= n; ++i) {
        if (arr[n - i] == 1) card.push_front(i);
        else if (arr[n - i] == 2) card.insert(++card.begin(), i);
        else if (arr[n - i] == 3) card.push_back(i);
    }

    for (int i = 0; i < n; ++i) cout << card[i] << ' ';
    cout << '\n';

    return 0;
}