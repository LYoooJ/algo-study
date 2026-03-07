#include <bits/stdc++.h>
using namespace std;

long long countOnes(long long n) {
    if (n <= 0) return 0;

    long long count = 0;
    long long bit = 1;

    while (bit <= n) {
        long long cycle = (n+1) / (bit*2);
        long long remainder = (n+1) % (bit*2);

        count += cycle * bit;

        if (remainder > bit) count += remainder - bit;
        if (bit > n/2) break;
        bit *= 2;
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << countOnes(b) - countOnes(a-1) << "\n";

    return 0;
}