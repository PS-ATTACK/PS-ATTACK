#include <bits/stdc++.h>

using namespace std;

#define MAX 100

#define pint pair<int,int>
#define vint vector<int>


// 100 101
// 1001 1000 1010
// 10010 ,, 10001 10000 10101 10100
/* 1000001
 * 1000101
 * 1001001
 * 1010001
 * 1010101
 *
 * 1000000
 * 1010000
 * 1010100
 * 1001010
 * 1001000
 * 1001010
 * 1000100
 * 1000010
 *
 *
 * */

long long dp[91]= {0,};
int n;

int main() {
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] =  2;
    // 10
    // 101 100
    // 1001 | 1010 1000
    // 10101 , 10001, || 10010 , 10100, 10000
    for (int i = 4; i < 91; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;

    return 0;
}
