#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int arr[100001], seg_tree[400005];

void build(int start, int end, int idx) {
    if (start == end) seg_tree[idx] = start;
    else {
        int mid = (start + end) / 2;
        build(start, mid, 2 * idx);
        build(mid + 1, end, 2 * idx + 1);

        if (arr[seg_tree[2 * idx]] <= arr[seg_tree[2 * idx + 1]]) {
            seg_tree[idx] = seg_tree[2 * idx];
        }
        else seg_tree[idx] = seg_tree[2 * idx + 1];
    }
}

void update(int start, int end, int idx, int target, int val) {
    if (start > target || target > end) return;
    else if (start == end) {
        if (start == target) arr[target] = val;
        return;
    }
    else {
        int mid = (start + end) / 2;
        update(start, mid, 2 * idx, target, val);
        update(mid + 1, end, 2 * idx + 1, target, val);

        if (arr[seg_tree[2 * idx]] <= arr[seg_tree[2 * idx + 1]]) {
            seg_tree[idx] = seg_tree[2 * idx];
        }
        else seg_tree[idx] = seg_tree[2 * idx + 1];
    }
}

int query(int start, int end, int idx, int left, int right) {
    if (start > right || end < left) return 0;
    else if (left <= start && end <= right) return seg_tree[idx];
    else {
        int mid = (start + end) / 2;
        
        int q1 = query(start, mid, 2 * idx, left, right);
        int q2 = query(mid + 1, end, 2 * idx + 1, left, right);

        if (arr[q1] <= arr[q2]) return q1;
        else return q2;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    arr[0] = (int) 1e9 + 1;

    build(1, n, 1);

    int m;
    cin >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;

        if (a == 1) update(1, n, 1, b, c);
        else if (a == 2) cout << query(1, n, 1, b, c) << '\n';
    }

    return 0;
}