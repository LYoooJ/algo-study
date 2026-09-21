#include <string>
#include <vector>
#include <iostream>
#define MAX_LEN 5
using namespace std;

int ans = 0, cnt = 0;
char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs (string& word, string s) {
    if (s.compare(word) == 0) {
        ans = cnt;
        return;   
    }
    if (s.size() == MAX_LEN) return;
    
    for (char c : vowels) {
        cnt++;
        dfs(word, s + c);
    }
}

int solution(string word) {
    dfs(word, "");
    return ans;
}