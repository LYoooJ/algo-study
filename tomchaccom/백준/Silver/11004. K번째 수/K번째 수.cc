#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    arr.resize(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << arr[m-1];
}