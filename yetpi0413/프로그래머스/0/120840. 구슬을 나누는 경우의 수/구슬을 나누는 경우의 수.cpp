#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long answer = 1;
    
    int r = (balls-share)>share?share:(balls-share);
    
    for(int i=0; i<r; i++){
        answer = answer * (balls-i) / (i+1);
    }
    
    return answer;
}