#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1001;
    int N = s.size();
    if (N == 1) return 1;
    
    for (int step = 1; step <= N / 2; step++) {
        string compressed = "";
        string prev = s.substr(0, step);
        int count = 1;
        
        for (int j = step; j < N; j += step) {
            string cur = s.substr(j, step);
            if (prev == cur) {
                count++;
            }
            else {
                if (count >= 2) {
                    compressed += to_string(count);
                }
                compressed += prev;
                
                prev = cur;
                count = 1;
            }
        }
        if (count >= 2) {
            compressed += to_string(count);
        }
        compressed += prev;
        answer = answer > compressed.size() ? compressed.size() : answer;
    }
    return answer;
}