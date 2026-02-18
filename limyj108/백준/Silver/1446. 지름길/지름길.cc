#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

struct shortcut {
	int s;
	int e;
	int l;

	bool operator< (const shortcut& other) const {
		return e < other.e;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, D, s, e, l, ans = INT_MAX;
	map<int, int> m;
	vector<shortcut> v;
	m[0] = 0;
	cin >> N >> D;

	for (int n = 0; n < N; n++) {
		cin >> s >> e >> l;
		v.push_back({ s, e, l });
	}

	sort(v.begin(), v.end());
    
	for (int i = 0; i < N; i++) {
		int start = 0;
		for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
			if (((v[i].e - iter->first + iter->second) < (v[i].e - start + m[start])) && iter->first <= v[i].s) {
				start = iter->first;
			}
		}

		int dist = v[i].l < (v[i].e - v[i].s) ? m[start] + (v[i].s - start) + v[i].l : m[start] + (v[i].s - start) + (v[i].e - v[i].s);
		if (m.find(v[i].e) != m.end()) { 
			m[v[i].e] = dist < m[v[i].e] ? dist : m[v[i].e];
		}
		else { 
			m[v[i].e] = dist;
		}
	}

	for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if (iter->first <= D && (D - iter->first + iter->second) < ans) {
			ans = (D - iter->first + iter->second);
		}
	}
	cout << ans << "\n";

	return 0;
}