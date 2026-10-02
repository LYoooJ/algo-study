#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> term_m;
int year, month, day;

bool is_expired(string s) {
    int valid_year = stoi(s.substr(0, 4)), valid_month = stoi(s.substr(5, 2)), valid_day = stoi(s.substr(8, 2));
    
    int valid = term_m[s[11]];
    
    valid_year += valid / 12;
    valid %= 12;
    valid_month += valid;
    if (valid_month > 12) {
        valid_month -= 12; valid_year++;
    }
    if (valid_day == 1) {
        if (valid_month == 1) {
            valid_month = 12; valid_year--;
        }
        else {
            valid_month--; 
        }
        valid_day = 28;
    }
    else valid_day--;
    
    if (valid_year > year) return false;
    else if (valid_year < year) return true;
    
    if (valid_month > month) return false;
    else if (valid_month < month) return true;
    
    return valid_day < day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int idx = 1;
    vector<int> answer;
    year = stoi(today.substr(0, 4)), month = stoi(today.substr(5, 2)), day = stoi(today.substr(8, 2));
    
    for (string term : terms) {
        term_m[term[0]] = stoi(term.substr(2));
    }
    for (string privacy : privacies) {
        if (is_expired(privacy)) {
            answer.push_back(idx);
        }
        idx++;
    }
    
    return answer;
}