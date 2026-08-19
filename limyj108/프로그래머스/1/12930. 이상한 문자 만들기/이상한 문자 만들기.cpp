#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int l = 0, size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == ' ') {
            l = 0;
            answer += ' ';
            continue;
        }
        if (l % 2 == 0) {
            if ('a' <= s[i] && s[i] <= 'z') 
                answer += s[i] - 32;
            else
                answer += s[i];
        }
        else {
            if ('A' <= s[i] && s[i] <= 'Z')
                answer += s[i] + 32;
            else
                answer += s[i];
        }
        l++;
    }
    return answer;
}