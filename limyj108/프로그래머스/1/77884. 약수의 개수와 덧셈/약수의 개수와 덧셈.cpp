#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int left, int right) {
    int ans = 0;
    set<int> squared;
    for (int i = 1; i <= 31; i++) {
        squared.insert(i * i);
    }
    for (int i = left; i <= right; i++) {
        if (squared.contains(i)) {
            ans -= i;
        }
        else {
            ans += i;
        }
    }
    return ans;
}