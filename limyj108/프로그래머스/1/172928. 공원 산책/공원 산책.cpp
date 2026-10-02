#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int R = park.size(), C = park[0].size();
    
    vector<int> answer;
    pair<int, int> cur;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (park[r][c] == 'S') {
                cur.first = r; cur.second = c;
            }
        }
    }
    
    for (string route : routes) {
        char dir = route[0];
        int dist = route[2] - '0';
        bool possible = true;
        pair<int, int> move;
        
        switch (dir) {
            case 'E': move = { 0, 1 }; break;
            case 'W': move = { 0, -1 }; break;
            case 'S': move = { 1, 0 }; break;
            case 'N': move = { -1, 0 }; break;
        }
        
        for (int d = 1; d <= dist; d++) {
            int new_r = cur.first + move.first * d, new_c = cur.second + move.second * d;
            if (!(0 <= new_r && new_r < R && 0 <= new_c && new_c < C && park[new_r][new_c] != 'X')) {
                possible = false; break;
            }
        }
        if (possible) {
            cur = {cur.first + move.first * dist, cur.second + move.second * dist};
        }
    }
    
    answer.push_back(cur.first); answer.push_back(cur.second);
    return answer;
}