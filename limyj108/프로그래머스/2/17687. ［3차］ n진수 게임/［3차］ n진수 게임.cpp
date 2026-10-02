#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> v = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

string convert_base(int n, int src) {
    string dst = "";
    do {
        dst = v[src % n] + dst;   
        src /= n;
    } while (src > 0);
    return dst;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0, turn = 0;
    bool end = false;
    
    while (true) {
        string converted = convert_base(n, num); num++;
        
        for (int i = 0; i < converted.size(); i++) {
            if ((turn % m + 1) == p) {
                answer.push_back(converted[i]);
                if (answer.size() == t) {
                    end = true;
                    break;
                }
            }
            turn++;
        }
        if (end) break;
    }
    return answer;
}

