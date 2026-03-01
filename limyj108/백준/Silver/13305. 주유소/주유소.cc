#include <iostream>
#include <vector>
#define MAX 1000000001

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, min_cost;
	long long oil = 0;
	cin >> N;

	vector<int> costs(N);
	vector<int> roads(N);

	for (int i = 0; i < N - 1; i++) {
		cin >> roads[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> costs[i];
	}

	min_cost = costs[0];
	for (int n = 0; n < N - 1; n++) {
		min_cost = min(min_cost, costs[n]);
		oil += (long long) min_cost * roads[n];
	}

	cout << oil << "\n";

	return 0;
}