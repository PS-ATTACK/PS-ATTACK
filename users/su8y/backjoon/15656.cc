//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int arr[9];
int res[9];
bool visited[9] = {0,};
string answers;
void dfs(int index){
    if(index == m){
        for(int i =0; i < m; i++){
            answers += to_string(res[i]) + " ";
        }
        answers += "\n";
        return;
    }
    for(size_t i = 0 ; i < n; i++){
        // if(!visited[i]){ // 중복없는 순열
        //     visited[i] = true;
            res[index] = arr[i];
            dfs(index+1);
        //     visited[i] = false;
        // }
    }
}
void solve(){
    cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    dfs(0);

    cout << answers; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    return 0;
}
