#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n<4) return answer;
    for(int i=4; i<=n; i++){
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                answer++;
                break;
            }
        }
    }
    return answer;
}