#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int l = 0, h = people.size() - 1;
    sort(people.begin(), people.end());
    while (l < h) {
        if ((people[l] + people[h]) <= limit) {
            l++;
        }
        h--;
        answer++;
    }
    if (l == h) {
        answer++;
    }
    
    return answer;
}