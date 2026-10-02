#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string to_two_base(int n) {
    string s = "";
    while (n > 0) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}

int solution(int n) {
    string s = to_two_base(n);
    int ans = n + 1, cnt = count(s.begin(), s.end(), '1');
    while (true) {
        string tmp = to_two_base(ans);
        if (count(tmp.begin(), tmp.end(), '1') == cnt) {
            break;
        }
        ans++;
    }
    return ans;
}