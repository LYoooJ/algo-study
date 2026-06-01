#include <string>
#include <vector>
#define DIV 1234567

using namespace std;

long long solution(int n) {
    vector<long long> D(n + 1, 0);
    D[1] = 1, D[2] = 2;
    for (int i = 3; i <= n; i++) {
        D[i] = (D[i - 2] + D[i - 1]) % DIV;
    }
    
    return D[n];
}