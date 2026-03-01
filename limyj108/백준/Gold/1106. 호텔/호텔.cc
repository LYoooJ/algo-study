#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C, N, x, y;
	cin >> C >> N;

	vector<int> D(C + 101, INT_MAX);
	vector<pii> v;

	D[0] = 0;
	for (int n = 0; n < N; n++) {
		cin >> x >> y;
        for (int j = y; j <= C + 100; j++) {
			if (D[j - y] != INT_MAX) {
				D[j] = min(D[j - y] + x, D[j]);
			}
		}
	}
	
	cout << *min_element(D.begin() + C, D.end()) << "\n";
	
	return 0;
}