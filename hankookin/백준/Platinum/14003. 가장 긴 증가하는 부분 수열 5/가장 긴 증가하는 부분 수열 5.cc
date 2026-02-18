#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> tail;
    vector<int> tailIdx;
    vector<int> parent(n,-1);
    vector<int> result;

    for (int i=0; i<n; i++) {
        int pos = lower_bound(tail.begin(), tail.end(), arr[i]) - tail.begin();

        if (pos == tail.size()) {
            tail.push_back(arr[i]);
            tailIdx.push_back(i);
        } else {
            tail[pos] = arr[i];
            tailIdx[pos] = i;
        }
        if (pos > 0) {
            parent[i] = tailIdx[pos-1];
        }
    }
    cout << tail.size() << "\n";

    int idx = tailIdx.back();
    while (idx >= 0) {
        result.push_back(arr[idx]);
        idx = parent[idx];
    }
    reverse(result.begin(), result.end());
    for (int x : result) cout << x << " ";
    
    return 0;
}