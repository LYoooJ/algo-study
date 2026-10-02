#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;
    string three_base = "";
    while (n > 0) {
        three_base += to_string(n % 3);
        n /= 3;
    }
    
    int d = 1;
    for (int i = three_base.size() - 1; i >= 0; i--) {
        ans += (three_base[i] - '0') * d;
        d *= 3;
    }
    return ans;
}