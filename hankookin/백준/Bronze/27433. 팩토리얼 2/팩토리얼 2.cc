#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n) {
    return (n <= 1) ? 1 : n * factorial(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N; cin >> N;
    cout << factorial(N) << '\n';

    return 0;
}