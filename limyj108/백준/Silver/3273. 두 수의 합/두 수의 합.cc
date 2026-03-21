#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	long long ans = 0;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x;

	sort(v.begin(), v.end());

	int s = 0, e = n - 1;

	while (s < e) {
		if (v[s] + v[e] == x) {
			s++;
			e--;
			ans++;
		}
		else if (v[s] + v[e] > x) {
			e--;
		}
		else { // v[s] + v[e] < x	
			s++;
		}
	}
	cout << ans;

	return 0;
}