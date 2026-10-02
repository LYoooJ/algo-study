#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
vector<bool> used;
set<string> case_set;
int ans = 0, b_size, N;

bool is_matched(string uid, string bid) {
    int b_size = bid.size();
    if (uid.size() != b_size) return false;
    for (int i = 0; i < b_size; i++) {
        if (bid[i] != uid[i] && bid[i] != '*')
            return false;
    }
    return true;
}

void dfs(int bidx, vector<string>& user_id, vector<string>& banned_id) {
    if (bidx == b_size) {
        string c = "";
        for (int idx = 0; idx < N; idx++) {
            c += to_string(used[idx]);
        }
        if (case_set.find(c) == case_set.end()) {
            ans++;
            case_set.insert(c);
        }
        return;
    } 
    for (int idx = 0; idx < N; idx++) {
        if (!used[idx] && is_matched(user_id[idx], banned_id[bidx])) {
            used[idx] = true;
            dfs(bidx + 1, user_id, banned_id);
            used[idx] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = user_id.size();
    b_size = banned_id.size();
    used.resize(N, false);
    dfs(0, user_id, banned_id);
    return ans;
}