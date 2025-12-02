//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n ,m;
string temp;
int arr[9];
bool visited[9] = {0,};
    
void dfs(int);
void solve(){
   cin >> n >> m; 
   dfs(0);
};
void dfs(int index){
    if( index == m){
        for(auto i : arr){
            if(i != 0) temp += to_string(i) + " "; 
        }
        temp += "\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        arr[index] = i;// 두번째 수
        dfs(index + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    cout << temp; 
    return 0;
}