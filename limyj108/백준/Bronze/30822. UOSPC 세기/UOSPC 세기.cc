#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string S;
	
	cin >> n >> S;
	vector<int> cnt(n, 0);

	for (int i = 0; i < n; i++) {
		if (S[i] == 'u')
			cnt[0]++;
		else if (S[i] == 'o')
			cnt[1]++;
		else if (S[i] == 's')
			cnt[2]++;
		else if (S[i] == 'p')
			cnt[3]++;
		else if (S[i] == 'c')
			cnt[4]++;
	}

	cout << *min_element(cnt.begin(), cnt.begin() + 5);

	return 0;
}