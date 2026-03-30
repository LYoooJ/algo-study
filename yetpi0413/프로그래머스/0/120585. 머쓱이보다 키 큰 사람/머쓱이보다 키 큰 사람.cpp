#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = count_if(array.begin(), array.end(), [height](int n){
        return n > height;
    });
    return answer;
}