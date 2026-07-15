#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int min = *min_element(number.begin(), number.end());
    int max = *max_element(number.begin(), number.end());
    for(int i=0; i<number.size()-2; i++){
        for(int j=i+1; j<number.size()-1; j++){
            for(int k=j+1; k<number.size(); k++){
                if(number[i]+number[j]+number[k]==0)    answer++;
            }
        }
    }
    return answer;
}