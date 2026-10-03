#include <string>
#include <vector>
#include <iostream>
#define MAX_LEN 5
using namespace std;

int ans = 0, cnt = 0;
char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs (string& word, string s) {
    cnt++;
    if (s.compare(word) == 0) {
        ans = cnt - 1;
        return;
    }
    if (s.size() == 5) return;
    for (char v : vowels) {
        dfs(word, s + v);
    }
}

int solution(string word) {
    dfs(word, "");
    return ans;
}