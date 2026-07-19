#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
string odd_str = "";
    string even_str = "";
    
    for (int num : num_list) {
        if (num % 2 != 0) {
            odd_str += to_string(num);
        } else {
            even_str += to_string(num);
        }
    }
        return stoi(odd_str) + stoi(even_str);
}