#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int l = absolutes.size(), sum = 0;
    for (int i = 0; i < l; i++) {
        if (signs[i])
            sum += absolutes[i];
        else
            sum -= absolutes[i];
    }
    return sum;
}