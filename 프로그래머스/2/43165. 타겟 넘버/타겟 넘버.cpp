#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<int>& numbers, int sum, int target, int idx) {
    if (idx == numbers.size()) {
        if (sum == target) ans++;
        return;
    }
    
    dfs(numbers, sum + numbers[idx], target, idx + 1);
    dfs(numbers, sum - numbers[idx], target, idx + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, target, 0);
    return ans;
}