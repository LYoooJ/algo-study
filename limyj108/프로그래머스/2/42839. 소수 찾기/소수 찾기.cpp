#include <string>
#include <vector>
#include <cmath>
#include <set>
#define MAX 10000000
#include <iostream>

using namespace std;

int max_depth;
vector<bool> prime(MAX, true);
set<int> prime_set;
vector<int> digits(10, 0);

void dfs(int n, int depth);
    
int solution(string numbers) {
    max_depth = numbers.size();
    prime[0] = false, prime[1] = false;
    
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (!prime[i])
            continue;
        for (int j = i * 2; j < MAX; j += i) {
            prime[j] = false;
        }
    }
    for (char c : numbers) {
        digits[c - '0'] += 1;
    }
    dfs(0, 0);
    return prime_set.size();
}

void dfs(int n, int depth) {
    if (prime[n])
        prime_set.insert(n);
    
    if (depth == max_depth) {
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (digits[i] > 0) {
            digits[i] -= 1;
            dfs(10 * n + i, depth + 1);
            digits[i] += 1;   
        }
    }
}