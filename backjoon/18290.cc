//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,k;
vector< vector<int> > map;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[11][11] = {0,};
static int max_sum = -999999;
void input();
int check(int x, int y){
    for (size_t i = 0; i < 4; i++) {
        int cx = x + dx[i]; 
        int cy = y + dy[i];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m) {
            if (visited[cx][cy]) {
                return 0;
            }
        }
    }
    return 1;
}
void dfs(int x, int y,int sum,int cnt){
    if( cnt == k){
        if(max_sum < sum) max_sum = sum;
        return;
    }
    // 이전 데이터는 조회할필요가 없기때문에 x y의 값을 넘겨주고 i > x즉 다음행으로 넘어간다면
    // y =0 으로 해준다.
    for (size_t i = x; i < n; i++) {
        if(i > x) y = 0;
        for (size_t j = y; j < m; j++) {
            if(visited[i][j] == false && check(i,j)){
                visited[i][j] = true;
                dfs(i, j, sum + map[i][j], cnt +1 );
                visited[i][j] = false;
            }
        }
    }
    

}
void solve(){
    input();
    // for(auto i : map){
    //     for(auto j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    dfs(0,0,0,0);
    cout << max_sum;
}

void input(){
    int tmp;
    cin >> n >> m >> k;
    map.resize(n,vector<int>(m));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    return 0;
}
