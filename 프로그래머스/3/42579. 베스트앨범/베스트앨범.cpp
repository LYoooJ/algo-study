#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int l = plays.size();    
    map<string, int> m;
    
    for (int i = 0; i < genres.size(); i++) {
        if (m.count(genres[i]) == 0)
            m[genres[i]] = plays[i];
        else
            m[genres[i]] += plays[i];
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
       return a.second > b.second; 
    });
    
    for (pair<string, int> p : v) {
        vector<pair<int, int>> id_play;
        for (int i = 0; i < l; i++) {
            if (genres[i] == p.first)
                id_play.push_back({i, plays[i]});
        }
        sort(id_play.begin(), id_play.end(), [] (const auto &a, const auto &b) {
            if (a.second > b.second)
                return true;
            else if (a.second < b.second)
                return false;
            return a.first < b.first;
        });
        answer.push_back(id_play[0].first);
        if (id_play.size() > 1)
            answer.push_back(id_play[1].first);
    }
    return answer;
}