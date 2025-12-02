//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int arr[9]; 
int res[9];
string result = "";
bool visited[9] = {0,};

void bt(int index){
    if(index == m){
        for(int i=0;i<m;i++){
            result += to_string(res[i]) + " ";
        }
        result += "\n";
        return;
    }
    sort(arr,arr+ n);
    for(int i = 0; i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            res[index] = arr[i];
            bt(index + 1);
            visited[i] = false;
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i =0; i <n; i++){
       cin >> arr[i]; 
    }    
    bt(0);
    cout << result << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    
    return 0;
}
