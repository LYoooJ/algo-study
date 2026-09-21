#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct work {
    int s;
    int l;
    bool operator< (const work& other) const {
        if (l > other.l)
            return true;
        else if (l < other.l)
            return false;
        return s > other.s;
    }
};

int solution(vector<vector<int>> jobs) {
    int timer = 0, n = jobs.size(), t = 0;
    priority_queue<work> pq;
    sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
        return a[0] > b[0];    
    });
    
    while (!(jobs.empty() && pq.empty())) {
        if (pq.empty() && jobs.back()[0] > timer) {
            timer = jobs.back()[0];
        }
        while (!jobs.empty() && jobs.back()[0] <= timer) {
            pq.push({jobs.back()[0], jobs.back()[1]});
            jobs.pop_back();
        }
        timer += pq.top().l;
        t += (timer - pq.top().s);
        pq.pop();
    }
    return t / n;
}