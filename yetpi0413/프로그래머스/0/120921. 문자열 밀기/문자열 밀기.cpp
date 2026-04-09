#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int len = A.length();
    string tmp="";
    for(int i=0; i<len; i++){
        tmp = A.substr(len-i,i) + A.substr(0, len-i);
        if(tmp==B){
            return i;
        }
    }
    return -1;
}