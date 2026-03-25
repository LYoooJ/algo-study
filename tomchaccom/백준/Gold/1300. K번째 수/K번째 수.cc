#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;
    int st = 1;
    int en = m;
    int ans = 0;

    while(st <= en){
        int mid = (st + en) / 2;
        int cnt =0;

        for(int i =1; i <= n; i++){
            cnt += min(mid / i, n); // 
        }

        if(cnt < m){
            st = mid + 1;
        }else{
            ans = mid;
            en = mid -1;
        }
    }

    cout << ans;
}