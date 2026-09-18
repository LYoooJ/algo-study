#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    string x = "";
    while (n > 0) {
        x += to_string(n % 3);
        n /= 3;
    }
    
    int answer = 0, d = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        answer += (x[i] - '0') * d;
        d *= 3;
    }
    return answer;
}