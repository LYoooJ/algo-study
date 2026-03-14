#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int max=0;
    int second=0;
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]>max){
            second = max;
            max=numbers[i];
        }
        else if(numbers[i]>second)  second=numbers[i];
    }
    answer = max*second;
    return answer;
}