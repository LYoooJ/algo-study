#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long pll = stoll(p), l = p.size();
    for (int i = 0; i + l <= t.size(); i++) {
        if (stoll(t.substr(i, l)) <= pll) {
            answer++;
        }
    }
    
    return answer;
}