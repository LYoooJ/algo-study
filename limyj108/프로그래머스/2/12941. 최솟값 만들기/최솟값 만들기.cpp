#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int sum = 0, N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for (int i = 0; i < N; i++) {
        sum += A[i] * B[N - 1 - i];
    }
    return sum;
}