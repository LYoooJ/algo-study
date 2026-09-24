#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string ans = "";
    int n = number.size(), len = n - k, start_idx = 0;
    
    for (int i = 0; i < len; i++) {
        int end_idx = k + i, max_idx = start_idx;
        char max_num = '0' - 1;
        
        for (int idx = start_idx; idx <= end_idx; idx++) {
            if (max_num < number[idx]) {
                max_num = number[idx];
                max_idx = idx;
            }
        }
        
        ans += number[max_idx];
        start_idx = max_idx + 1;
    }
    
    return ans;
}