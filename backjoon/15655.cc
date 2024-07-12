//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

// int arr[9] = {1,2,3,4,0,};
int arr[9];
int res[9];
bool visited[9]={0,};

string ans;
void dfs(int index,int num){
    if(index == m){
        for(int i =0; i < m ;i++){
            ans += to_string(res[i]) + " ";
        }
        ans += "\n";
        return;
    }
    for(size_t i = num; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            res[index] = arr[i];
            dfs(index+1,i);
            visited[i] = false;
        }
    }
}

void solve(){
    cin >> n >> m;    
    // n =4 , m = 2;
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    dfs(0,0);
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    return 0;
}
