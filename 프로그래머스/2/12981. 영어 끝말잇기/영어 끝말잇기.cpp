#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    s.insert(words[0]);
    
    for (int i = 1; i < words.size(); i++) {
        if (s.contains(words[i]) || (words[i - 1][words[i - 1].size() - 1] != words[i][0])) {
            answer[0] = i % n + 1;
            answer[1] = (i + n) / n;
            break;
        }
        else {
            s.insert(words[i]);
        }
    }
    return answer;
}