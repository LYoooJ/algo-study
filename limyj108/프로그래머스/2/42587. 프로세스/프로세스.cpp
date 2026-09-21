#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

struct process{
    int loc;
    int priority;
    bool operator< (const process& other) const {
        return priority < other.priority;
    }
};

int solution(vector<int> priorities, int location) {
    int ans = 1;
    priority_queue<process> pq;
    deque<process> dq;
    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back({ i, priorities[i] });
        pq.push({ i, priorities[i] });
    }
   
    while (!dq.empty()) {
        if (dq.front().priority == pq.top().priority){
            if (dq.front().loc == location) 
                return ans;
            dq.pop_front();
            pq.pop();
            ans++;
        }
        else {
            dq.push_back({dq.front().loc, dq.front().priority});
            dq.pop_front();
        }
    }
    
    return ans;
}