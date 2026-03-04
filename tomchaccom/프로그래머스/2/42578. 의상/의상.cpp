#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> mp;
    
    for(auto &p : clothes){
        mp[p[1]]++;
    }
    
    for(auto x : mp){
        answer*= (x.second + 1);
        
    }
    
    
    return answer -1 ;
}