#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct point {
	int r, c, d, p;
};

int N;
string dalgu, ponix;
map<char, point> drc = { {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}} };
point s, e;
vector<vector<char>> board;

bool is_valid(point p) {
	return 0 <= p.r && p.r < N && 0 <= p.c && p.c < N;
}

int bfs() {
	int d_size = dalgu.size(), p_size = ponix.size();
	queue<point> q;
	vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(N, vector<vector<bool>>(d_size + 1, vector<bool>(p_size + 1, false))));
	q.push({ s.r, s.c, 0, 0});
	visited[s.r][s.c][0][0] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.d < d_size) {
			int dr = drc[dalgu[cur.d]].r, dc = drc[dalgu[cur.d]].c;
			point next = { cur.r + dr, cur.c + dc, cur.d + 1, cur.p };

			if (!is_valid(next) || board[next.r][next.c] == '#') {
				next.r = cur.r, next.c = cur.c;
			}
			if (!visited[next.r][next.c][next.d][next.p]) {
				q.push(next);
				visited[next.r][next.c][next.d][next.p] = true;
				if (next.r == e.r && next.c == e.c) {
					return next.d + next.p;
				}
			}
		}

		if (cur.p < p_size) {
			int dr = drc[ponix[cur.p]].r, dc = drc[ponix[cur.p]].c;
			point next = { cur.r + dr, cur.c + dc, cur.d, cur.p + 1 };

			if (!is_valid(next) || board[next.r][next.c] == '#') {
				next.r = cur.r, next.c = cur.c;
			}
			if (!visited[next.r][next.c][next.d][next.p]) {
				q.push(next);
				visited[next.r][next.c][next.d][next.p] = true;
				if (next.r == e.r && next.c == e.c) {
					return next.d + next.p;
				}
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;

	cin >> N;
	board.resize(N, vector<char>(N));

	for (int r = 0; r < N; r++) {
		cin >> str;
		for (int c = 0; c < N; c++) {
			board[r][c] = str[c];
			if (board[r][c] == 'S') {
				s = { r, c };
			}
			else if (board[r][c] == 'E') {
				e = { r, c };
			}
		}
	}
	
	cin >> dalgu >> ponix;
	cout << bfs();

	return 0;
}