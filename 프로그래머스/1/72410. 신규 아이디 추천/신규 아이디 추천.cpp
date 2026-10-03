#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string step1 = "";
    for (int i = 0; i < new_id.size(); i++) {
        if ('A' <= new_id[i] && new_id[i] <= 'Z') step1.push_back(new_id[i] + 32);
        else step1.push_back(new_id[i]);
    }
    
    string step2 = "";
    for (int i = 0; i < step1.size(); i++) {
        if (!(('a' <= step1[i] && step1[i] <= 'z') || ('0' <= step1[i] && step1[i] <= '9') || step1[i] == '-' || step1[i] == '_' || step1[i] == '.')) continue;
        else step2.push_back(step1[i]);
    }
    
    string step3 = "";
    if (!step2.empty()) {
        step3.push_back(step2[0]); char prev = step2[0];
        for (int i = 1; i < step2.size(); i++) {
            if (step2[i] == '.' && prev == '.') continue;
            step3.push_back(step2[i]); prev = step2[i];
        }     
    } 
    else step3 = step2;
    
    string step4;
    if (!step3.empty() && step3[step3.size() - 1] == '.') step4 = step3.substr(0, step3.size() - 1);
    else step4 = step3;
    if (!step4.empty() && step3[0] == '.') step4 = step4.substr(1);
    
    string step5;
    if (step4.empty()) step5 = "a";
    else step5 = step4;
    
    string step6;
    if (step5.size() >= 16) {
        step6 = step5.substr(0, 15);
        int end = 14;
        while (step6[end] == '.') {
            step6 = step6.substr(0, end--);
        }
    }
    else step6 = step5;
    
    string step7;
    if (step6.size() <= 2) {
        step7 = step6; char end_c = step6[step6.size() - 1];
        while (step7.size() < 3) {
            step7 += end_c;
        }
    }
    else step7 = step6;
    
    return step7;
}