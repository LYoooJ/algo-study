#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    int index = it - seoul.begin();
    
    answer = "김서방은 "+to_string(index)+"에 있다";
    return answer;
}