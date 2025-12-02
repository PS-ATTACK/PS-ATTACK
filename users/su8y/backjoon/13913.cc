//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;


int n,k, result = 0;
int cnt = 0;
bool visited[100001]{0,};
deque< pair<int,int> > q;
int cntMap(){
    for (auto &i : q){
        if(i.first == k && i.second == result){
            cnt++;
        }
    }
}
bool valid(int n ){
    if (n < 0 || n > 100000 || visited[n] == true){
        return false;
    }
    return true;
}
void bfs(){
    while(!q.empty()){
        
        int data = q.front().first;
        int depth = q .front().second; 
        q.pop_front();
        visited[data] = true; 
        //
        if( data == k){
            result = depth;
            cnt++;
            cntMap();
            break;
        }
        if(valid(data - 1)){
            
            q.push_back({data - 1, depth + 1});
        }
        if(valid(data + 1)){
           
            q.push_back({data + 1, depth + 1});

        }
        if(valid(data * 2)){
          
            q.push_back({data * 2, depth + 1});

        }
    }
    
}
void solve(){
    cin >> n >> k;
    q.push_back({n,0});
    bfs();
    cout << result << endl;
    cout <<cnt;
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();

    return 0;
}
