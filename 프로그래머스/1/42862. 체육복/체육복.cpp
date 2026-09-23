#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes(n + 2, 1);
    clothes[0] = 0, clothes[n + 1] = 0;
    for (int i = 0; i < lost.size(); i++) clothes[lost[i]]--; 
    for (int i = 0; i < reserve.size(); i++) clothes[reserve[i]]++;
    
    for (int i = 1; i <= n; i++) {
        if (clothes[i] == 0) {
            if (clothes[i - 1] > 1) {
                clothes[i - 1]--; answer++;
            } 
            else if (clothes[i + 1] > 1) {
                clothes[i + 1]--; answer++;
            }
        } else {
            answer++;
        }
    }
    return answer;
}