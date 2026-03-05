#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 1;
    queue<pair<int,int>> q;
    
    for(int i = 0; i < speeds.size(); i++){
        q.push({progresses[i], speeds[i]});
    }
    
    while(!q.empty()){
        int feature = 0;
        
        auto [pro, spe] = q.front();
        
        if(pro + spe * day >= 100){
            q.pop();
            feature++;
            
            while(1){
                auto [pr, sp] = q.front();
                
                if(pr + sp * day >= 100){
                    q.pop();
                    feature++;
                }else{
                    answer.push_back(feature);
                    break;
                }
                
            }
        }
        
        day++;
    }
    
    
    return answer;
    
    
    
}