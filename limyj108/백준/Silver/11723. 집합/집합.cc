#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M, x;
	string cmd;
	bool S[21] = { false, };
	
	cin >> M;

	for (int m = 0; m < M; m++) {
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			cin >> x;
			S[x] = true;
		}
		else if (cmd.compare("remove") == 0) {
			cin >> x;
			S[x] = false;
		}
		else if (cmd.compare("check") == 0) {
			cin >> x;
			cout << S[x] << "\n";
		}
		else if (cmd.compare("toggle") == 0) {
			cin >> x;
			S[x] = !S[x];
		}
		else if (cmd.compare("all") == 0) {
			for (int i = 1; i < 21; i++) {
				S[i] = true;
			}
		}
		else if (cmd.compare("empty") == 0) {
			for (int i = 1; i < 21; i++) {
				S[i] = false;
			}
		}
	}
		
	return 0;
}