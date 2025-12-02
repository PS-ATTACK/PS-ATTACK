//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;


int n,k, result = 0;
int visited[100001]{0};
queue< pair<int,int> > q;

bool valid(int n ){
    if (n < 0 || n > 100000 || visited[n] > 0){
        return false;
    }
    return true;
}
void bfs(){
    while(!q.empty()){
        
        int data = q.front().first;
        int depth = q .front().second; 
        q.pop();
        
        //
        if( data == k){
            result = depth;
            break;
        }
        if(valid(data - 1)){
            visited[data - 1] = true;
            q.push({data - 1, depth + 1});
        }
        if(valid(data + 1)){
            visited[data + 1] = true;
            q.push({data + 1, depth + 1});

        }
        if(valid(data * 2)){
            visited[data * 2] = true;
            q.push({data * 2, depth + 1});

        }
    }
    
}
void solve(){
    cin >> n >> k;
    q.push({n,0});
    visited[n] = true;
    bfs();
    cout << result;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();

    return 0;
}
