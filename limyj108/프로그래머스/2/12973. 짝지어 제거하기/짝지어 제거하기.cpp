#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int l = s.size();
    stack<char> stk;
    
    for (int i = 0; i < l; i++) {
        if (stk.empty()) {
            stk.push(s[i]);
        }
        else {
            if (s[i] == stk.top()) {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
    }
    return stk.empty() ? 1 : 0;
}