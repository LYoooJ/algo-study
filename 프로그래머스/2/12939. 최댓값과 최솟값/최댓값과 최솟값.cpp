#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string ans;
    int s_idx = 0, e_idx = 1, num, iter = 0;
    int min_value, max_value;
    while (e_idx < s.size()) {
        while (s[s_idx] == ' ') {
            s_idx++; e_idx++;
        }
        if (s[s_idx] == '-') {
            while ('0' <= s[e_idx] && s[e_idx] <= '9') {
                e_idx++;
            }
        }
        else {
            while ('0' <= s[e_idx] && s[e_idx] <= '9') {
                e_idx++;
            }
        }

        num = stoi(s.substr(s_idx, e_idx - s_idx));
        if (iter == 0) {
            max_value = num;
            min_value = num;
        }
        else if (max_value < num) max_value = num;
        else if (min_value > num) min_value = num;
        
        s_idx = e_idx; e_idx++; iter++;
    }
    ans = to_string(min_value) + " " + to_string(max_value);
    return ans;
}