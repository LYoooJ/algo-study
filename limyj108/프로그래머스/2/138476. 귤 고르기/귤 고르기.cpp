#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    int ans = 0;
    
    for (int size_ : tangerine) {
        m[size_] += 1;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const auto &a, const auto& b) {
        return a.second < b.second;
    });
    
    while (k > 0) {
        k -= v.back().second;
        v.pop_back();
        ans++;
    }
    return ans;
}