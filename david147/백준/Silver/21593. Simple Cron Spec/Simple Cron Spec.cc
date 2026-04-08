#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    vector<int> job(86400, 0);
    while (t--) {
        string hour, minute, second;
        cin >> hour >> minute >> second;

        vector<bool> h(24, false);
        if (hour == "*") h.assign(24, true);
        else {
            int cur = 0, start = -1;
            for (int i = 0; i < hour.size(); ++i) {
                if (hour[i] >= '0' && hour[i] <= '9') {
                    cur *= 10;
                    cur += hour[i] - '0';
                }
                else {
                    if (hour[i] == '-') start = cur;
                    else if (hour[i] == ',') {
                        if (start == -1) h[cur] = true;
                        else {
                            for (int j = start; j <= cur; ++j) h[j] = true;
                            start = -1;
                        }
                    }
                    cur = 0;
                }
            }
            if (start == -1) h[cur] = true;
            else {
                for (int j = start; j <= cur; ++j) h[j] = true;
                start = -1;
            }
        }

        // for (int i = 0; i < h.size(); ++i) cout << h[i] << ' ';
        // cout << '\n';

        vector<bool> m(60, false);
        if (minute == "*") m.assign(60, true);
        else {
            int cur = 0, start = -1;
            for (int i = 0; i < minute.size(); ++i) {
                if (minute[i] >= '0' && minute[i] <= '9') {
                    cur *= 10;
                    cur += minute[i] - '0';
                }
                else {
                    if (minute[i] == '-') start = cur;
                    else if (minute[i] == ',') {
                        if (start == -1) m[cur] = true;
                        else {
                            for (int j = start; j <= cur; ++j) m[j] = true;
                            start = -1;
                        }
                    }
                    cur = 0;
                }
            }
            if (start == -1) m[cur] = true;
            else {
                for (int j = start; j <= cur; ++j) m[j] = true;
                start = -1;
            }
        }

        // for (int i = 0; i < m.size(); ++i) cout << m[i] << ' ';
        // cout << '\n';

        vector<bool> s(60, false);
        if (second == "*") s.assign(60, true);
        else {
            int cur = 0, start = -1;
            for (int i = 0; i < second.size(); ++i) {
                if (second[i] >= '0' && second[i] <= '9') {
                    cur *= 10;
                    cur += second[i] - '0';
                }
                else {
                    if (second[i] == '-') start = cur;
                    else if (second[i] == ',') {
                        if (start == -1) s[cur] = true;
                        else {
                            for (int j = start; j <= cur; ++j) s[j] = true;
                            start = -1;
                        }
                    }
                    cur = 0;
                }
            }
            if (start == -1) s[cur] = true;
            else {
                for (int j = start; j <= cur; ++j) s[j] = true;
                start = -1;
            }            
        }

        // for (int i = 0; i < s.size(); ++i) cout << s[i] << ' ';
        // cout << '\n';

        for (int i = 0; i < 24; ++i) {
            if (!h[i]) continue;
            for (int j = 0; j < 60; ++j) {
                if (!m[j]) continue;
                for (int k = 0; k < 60; ++k) {
                    if (!s[k]) continue;

                    ++job[3600 * i + 60 * j + k];
                }
            }
        }
    }

    int a1 = 0, a2 = 0;
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {
            for (int k = 0; k < 60; ++k) {
                if (job[3600 * i + 60 * j + k]) {
                    ++a1; a2 += job[3600 * i + 60 * j + k];
                }
            }
        }
    }

    cout << a1 << ' ' << a2 << '\n';

    return 0;
}