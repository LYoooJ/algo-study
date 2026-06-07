#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    if(answer.size()==1){
        answer.pop_back();
        answer.push_back(-1);
    }
    else{
        int min = *min_element(answer.begin(), answer.end());
        answer.erase(find(answer.begin(),answer.end(),min));
    }
    
    return answer;
}