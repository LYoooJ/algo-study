#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0; 
    int prev;
    for (string skill_tree : skill_trees) {
        bool flag = false; prev = -1;
        
        for (int i = 0; i < skill.size(); i++) {
            int pos = skill_tree.find(skill[i]);
            
            if (pos != -1) {
                if (prev == -1) {
                    if (i == 0) {
                        prev = pos;     
                    } 
                    else {
                        flag = true; break;   
                    }
                }
                else { // prev != -1
                    if (skill_tree[prev] == skill[i - 1] && prev < pos) {
                        prev = pos;
                    }
                    else {
                        flag = true; break;   
                    }
                }
            }
        }
        if (!flag) answer++;
    }
    return answer;
}