#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    for (int i = 0; i < s.size(); ) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            i++;
            continue;
        }
        int j = i + 1;
        
        while ('0' <= s[j] && s[j] <= '9') {
            j++;
        }
        m[stoi(s.substr(i, j - i))] += 1;
        i = j + 1;
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [] (const auto &a, const auto &b) {
        return a.second > b.second; 
    });
    
    for (int i = 0; i < (count(s.begin(), s.end(), '{') - 1); i++) {
        answer.push_back(v[i].first);
    }
    return answer;
}