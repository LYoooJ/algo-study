#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int len=0;
    for(int i=0; i<num; i++){
        len += i;
    }
    int begin = (total-len)/num;
    for(int i=0; i<num; i++){
        answer.push_back(begin+i);
    }
    return answer;
}