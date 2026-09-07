#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 20001

using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0, n = t.size();
    vector<int> dp(n + 1, MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (const string& s : strs) {
            int l = s.size();
            if (i - l >= 0) {
                if (t.compare(i - l, l, s) == 0) {
                    dp[i] = min(dp[i], dp[i - l] + 1);
                }
            }
        }
    }
    
    return dp[n] == MAX ? -1 : dp[n]; 
}