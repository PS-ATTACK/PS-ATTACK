#include <iostream> 
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
/*
4 6
101111
101010
101011
111011
*/
using namespace std;
int arr[101][101];
int cnt[101][101];
int check[101][101];
int ny[4] = {1,0,-1,0};
int nx[4] = {0,1,0,-1}; 
int n,m;
void bfs(int x,int y){
    check[x][y] = 1;
    cnt[x][y] = 1;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4;i++){
            int nxtX = x + nx[i];
            int nxtY = y + ny[i];
            if(arr[nxtX][nxtY] == 1 && check[nxtX][nxtY] == 0){
                q.push(make_pair(nxtX,nxtY));
                check[nxtX][nxtY] = 1;
                cnt[nxtX][nxtY] = cnt[x][y] +1;
            }
        }

    }
}
int main(){

    int min = 0;
    scanf("%d %d" ,&n , &m);
    // vector<vector<int> > check (n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j =0;j <m;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    bfs(0,0);
    printf("%d",cnt[n-1][m-1]);
}
// int nx[4] = {0,1,0,-1};
// int ny[4] = {1,0,-1,0};
// bool isa = false;
// int minValue = 0;
// int n,m;
// int arr[101][101];
// int check[101][101]={0};
// // vector<vector<int> > arr(100);
// //x,y 시작
// void dfs(int x,int y,int cnt){
//     if(x < 0 || y < 0 || x >= n || y >= m) return;
//     if(x == n-1 && y == m-1) {
//         minValue = cnt;
//         return; 
//     }
//     for(int i =0; i < 4;i++){
//         if(check[x + nx[i]][y + ny[i]] == 0 && arr[x+nx[i]][y+ny[i]] == 1){
//             check[x + nx[i]][y +ny[i]] = 1;
//             dfs(x+nx[i],y+ny[i],cnt+1);
//             check[x + nx[i]][y +ny[i]] = 0;
//         }
//     }
// }
// int main(){
    // int min = 0;
    // scanf("%d %d" ,&n , &m);
    // // vector<vector<int> > check (n,vector<int>(m,0));

    // for(int i=0;i<n;i++){
    //     for(int j =0;j <m;j++){
    //         scanf("%1d",&arr[i][j]);
    //         // arr[i].push_back(tmp);
    //     }
    // }
//     // for(int i=0;i<n;i++){ for(int j =0;j <m;j++){ printf("%d",arr[i][j]); } printf("\n"); }
//     dfs(0,0,1);
//     printf("%d" ,minValue);

//     return 0;
// }
