//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n , m;  
int arr[9];

void bt(int num,int index){
    if (index == m) {
        for (size_t i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = num; i <= n; i++){
        arr[index] = i;
        bt(i,index + 1);
    }
    
}
void solve(){
    cin >> n >> m; 
    bt(1,0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    
    return 0;
}
