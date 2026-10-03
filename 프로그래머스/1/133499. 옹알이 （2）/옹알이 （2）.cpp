#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int ans = 0;
    string two[2] = {"ye", "ma"};
    string three[2] = {"aya", "woo"};
    
    for (string babb : babbling) {
        int s = 0; string prev = "";
        while (s < babb.size()) {
            bool flag = false;
            if (s + 1 < babb.size()) {
                for (string x : two) {
                    if (babb.substr(s, 2).compare(x) == 0 && prev.compare(x) != 0) {
                        prev = x; flag = true; s += 2;
                    }   
                }
            }
            if (s + 2 < babb.size()) {
                for (string x : three) {
                    if (babb.substr(s, 3).compare(x) == 0 && prev.compare(x) != 0) {
                        prev = x; flag= true; s += 3;
                    }
                }
            }
            if (!flag) break;
        }
        if (s == babb.size()) ans++;
    }
    return ans;
}