#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    map<int, int> num;
    for(int n: numbers){
        num[n]++;
    }
    for(int i=0; i<10; i++){
        if(num[i]>0)    continue;
        answer += i;
    }
    return answer;
}