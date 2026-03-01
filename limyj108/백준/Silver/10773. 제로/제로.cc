#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, n, sum = 0;
	stack<int> stk;
	cin >> K;

	for (int k = 0; k < K; k++) {
		cin >> n;
		if (n == 0) {
			stk.pop();
		}
		else {
			stk.push(n);
		}
	}

	while (!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}

	cout << sum;
	
	return 0;
}