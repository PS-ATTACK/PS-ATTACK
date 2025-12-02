//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
bool visited[1001]{0};
vector<vector<int> >arr; // n의 크기로 0 초기화
void dfs(int x){
    cout << x << " ";
    visited[x] = true;
    for(int i = 0; i <arr[x].size(); i++){
        int y = arr[x][i];
        if(!visited[y]){
            dfs(y);
        }
    } 
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i =0; i <arr[x].size();i++){
            int y = arr[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] =true; 
            }
        }
    }
}
void solve(){
    int n,m,v;
    cin >> n >> m >> v; // node count :n  line : m start : v;
    arr.resize(n+1);
    for (size_t i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (auto &i : arr){
        sort(i.begin(),i.end());
    }
    dfs(v);
    cout << endl;
    std::fill_n(visited,1001,0);
    bfs(v);
    cout << endl;
    // for (auto &&i : arr) {
    //     for (auto &&j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    
    


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();

    return 0;
}
