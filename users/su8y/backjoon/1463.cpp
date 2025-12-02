//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
/*
    dp[0] = 0
    dp[1] = 0
    dp[2] = 1
    dp[3] = 1
    dp[4] = 2 , 4/2 2/2 1, 4 -1 3/3 1
    dp[5] = 3  , 5 - 1 4 /2 2/2 1 , 5- 1, 4-1 3/3 1
    dp[6] = 3 , 6/3 2/2 , 6/2 3/3 
    dp[7]      7 - 1 6/3 2/2
    dp[8]      8/2 + dp[4]
    dp[9]      9/3 + dp[3] , 9 - 1 dp[8]
    dp[10]     
    dp[n] = [n-1] + 1
    dp[n] = dp[n/3] + 1
    dp[n] = dp[n/2] + 1
*/
using namespace std;
int dp[1000001]{0,0,1,1};

void solve(){
    int answers;
    int n;

    cin >>n;
    for(int i = 4;i <= n; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0){
            dp[i] = min(dp[i],dp[i/2] + 1);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i],dp[i/3] + 1);
        }
    }
    cout << dp[n];
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();

    return 0;
}
