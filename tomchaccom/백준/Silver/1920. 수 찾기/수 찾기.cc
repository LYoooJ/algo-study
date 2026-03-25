#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> ar;

bool binarySearch(int st, int en, int key){

    int mid = (st + en) / 2;
    
    if(st > en){
        return 0;
    }

    if(arr[mid] == key){
        return true;
    }else if(arr[mid] > key ){
        return binarySearch(st,mid-1,key);
    }else return binarySearch(mid+1, en,key);

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ,m;
    cin >> n;
    arr = vector<int> (n);
    

    for(int i =0 ; i < n; i++){
        cin >> arr[i]; 
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    ar = vector<int> (m);

    for(int i =0 ; i < m; i++){
        cin >> ar[i];
        cout << binarySearch(0, n-1, ar[i]) << "\n";
    }

}