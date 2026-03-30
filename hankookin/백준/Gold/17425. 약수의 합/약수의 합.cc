#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    vector<int> nums(T);
    int max_num = 0;
    for (int i=0; i<T; i++) {
        cin >> nums[i];
        if (nums[i] > max_num) max_num = nums[i];
    }
    
    vector<long long> factors(max_num+1,0);
    vector<long long> prefix_sum(max_num+1,0);
    prefix_sum[0] = 0;
    for (int i=1; i<=max_num; i++) {
        for (int j=i; j<=max_num; j+=i) {
            factors[j] += i;
        }
    }
    for (int i=1; i<=max_num; i++) {
        prefix_sum[i] = prefix_sum[i-1] + factors[i];
    }
    
    for (int i=0; i<T; i++) {
        cout << prefix_sum[nums[i]] << "\n";
    }

    return 0;
}