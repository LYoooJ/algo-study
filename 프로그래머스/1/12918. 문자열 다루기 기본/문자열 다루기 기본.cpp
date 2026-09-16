#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int l = s.size();
    if (l != 4 && l != 6)
        return false;
    for (int i = 0; i < l; i++) {
        if (!('0' <= s[i] && s[i] <='9'))
            return false;
    }
    return true;
}