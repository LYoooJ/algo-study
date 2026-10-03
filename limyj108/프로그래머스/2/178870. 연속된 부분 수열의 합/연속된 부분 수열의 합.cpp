#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int l = 0, r = 0, n = sequence.size();
    int ans_l, ans_r, min_len = 1000001;
    int sum = sequence[0];

    while (l < n && r < n) {
        if (sum < k) {
            r++;
            if (r < n) sum += sequence[r];
        }
        else if (sum > k) {
            sum -= sequence[l];
            l++;
        }
        else {
            if (r - l + 1 < min_len) {
                ans_l = l, ans_r = r;
                min_len = r - l + 1;
            }
            r++;
            sum += sequence[r];
        }
    }
    answer.push_back(ans_l); answer.push_back(ans_r);
    return answer;
}