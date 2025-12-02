//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n ,m;
bool visited[9] = {0};
int arr[9];
string answers;

void dfs(int index){
    if(index ==m ){
        for (size_t i = 0; i < m; i++) {
            answers += to_string(arr[i]) + " ";
        }
        answers += "\n";
        
    }
    for (int i = 1; i <= n; i++) {
       if(!visited[i]){
           visited[i] = true;
           arr[index] = i;
           dfs(index + 1);
           visited[i]= false;
       } 
    }
}
void solve(){
    cin >> n >> m;
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
