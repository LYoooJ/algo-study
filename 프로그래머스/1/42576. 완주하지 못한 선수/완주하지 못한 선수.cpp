#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    for (string name : participant) {
        m[name] += 1;
    }
    
    for (string name : completion) {
        if (m[name] == 1) {
            m.erase(name);
        }
        else
            m[name]--;
    }
    return m.begin()->first;
}