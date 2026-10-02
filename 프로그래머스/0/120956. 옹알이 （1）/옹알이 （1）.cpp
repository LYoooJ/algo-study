#include <string>
#include <vector>
#include <iostream>

using namespace std;

string babb[4] = { "aya", "ye", "woo", "ma" };

int solution(vector<string> babbling) {
    int answer = 0;
    for (string str : babbling) {
        int s = 0;
        while (s < str.size()) {
            bool f = false;
            if (s + 1 < str.size()) {
                if (str.substr(s, 2).compare("ye") == 0) {
                    f = true; s += 2;                    
                }
                if (str.substr(s, 2).compare("ma") == 0) {
                    f = true; s += 2;
                }
            }
            if (s + 2 < str.size()) {
                if (str.substr(s, 3).compare("aya") == 0) {
                    f = true; s += 3;
                }
                if (str.substr(s, 3).compare("woo") == 0) {
                    f = true; s += 3;
                }
            }
            if (!f)
                break;
        }
        if (s == str.size()) {
            answer++;
        }
    }
    
    return answer;
}