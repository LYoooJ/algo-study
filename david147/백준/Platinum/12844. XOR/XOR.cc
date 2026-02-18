#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)
#define N 500000

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[500001], seg_tree[2000001], lazy[2000001];

void force(int start, int end, int index) {
    if (lazy[index]) {
        if ((end - start + 1) & 1) seg_tree[index] ^= lazy[index];

        if (start < end) {
            lazy[2 * index] ^= lazy[index];
            lazy[2 * index + 1] ^= lazy[index];
        }
        lazy[index] = 0;
    }
}

void build(int start, int end, int index) {
    if (start == end) {seg_tree[index] = arr[start]; return;}

    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);

    seg_tree[index] = seg_tree[2 * index] ^ seg_tree[2 * index + 1];
}

void update(int start, int end, int index, int left, int right, int value) {
    force(start, end, index);
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
        if ((end - start + 1) & 1) seg_tree[index] ^= value;

        if (start < end) {
            lazy[2 * index] ^= value;
            lazy[2 * index + 1] ^= value;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, 2 * index, left, right, value);
    update(mid + 1, end, 2 * index + 1, left, right, value);

    seg_tree[index] = seg_tree[2 * index] ^ seg_tree[2 * index + 1];
}

int query(int start, int end, int index, int left, int right) {
    force(start, end, index);
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return seg_tree[index];

    int mid = (start + end) / 2;
    return query(start, mid, 2 * index, left, right) ^ query(mid + 1, end, 2 * index + 1, left, right);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(0, n - 1, 1);

    cin >> m;
    int a, b, c, d;
    for (int i = 0; i < m; i++) {
        cin >> a;
        
        if (a == 1) {
            cin >> b >> c >> d;
            update(0, n - 1, 1, b, c, d);
        }
        else if (a == 2) {
            cin >> b >> c;
            cout << query(0, n - 1, 1, b, c) << '\n';
        }

        // for (int j = 0; j < 4 * (n - 1); j++) cout << seg_tree[j] << ' ';
        // cout << '\n';
    }

    return 0;
}