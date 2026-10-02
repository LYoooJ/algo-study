#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    vector<int> fac(11, 0);
    fac[0] = 1;
    for (int i = 1; i <= 10; i++) {
        fac[i] = fac[i - 1] * i;
    }
    
    int i;
    for (i = 1; i <= 10; i++) {
        if (n < fac[i]) break;
    }
    return i - 1;
}