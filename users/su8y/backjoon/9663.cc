#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt = 0;

// int map[15];
vector<int> map;

int check(int y){
    for (size_t i = 0; i < y; i++)
    {
        if(map[y] == map[i] || y - i  == abs(map[y] - map[i]))
        return 0;
    }
        return 1;
    
}

void solve( int depth){
    if(depth == n){
        cnt = cnt + 1;
        return;
    }

    for(int i = 0; i < n;i++){
        map[depth] = i;
        if(check(depth)){
            solve(depth + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // clock_t f,s;
    cin >> n; 
    // s = clock();
    map.resize(n,-1);

    solve(0);
    cout << cnt << endl;;
    // f = clock();
    // cout << (f-s)/CLOCKS_PER_SEC;

    return 0;
}
