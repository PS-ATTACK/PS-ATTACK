#include <bits/stdc++.h>

#define pii Pair<int, int>
#define pis Pair<int, string>
#define pdd Pair<double, double>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

#define PRECODE template<typename T1, typename T2> struct Pair{ T1 y; T2 x; };
PRECODE

using namespace std;

int t, n;
int dp[1000001] = {0, 1, 0, 1, 0,};

int main() {
    FAST_IO
    for (int i = 4; i < 1000001; i++) {
        for (int j = 1; j * j <= i; j++) {
            int ni = i - j * j;
            /* 한번이라도 이길수 없는 상태를 상대에게 넘겨 줄 수 있다면 선공권을 가지고있는 a의 승리*/
            if (dp[ni] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        if (dp[n]) {
            cout << "koosaga\n";
        } else {
            cout << "cubelover\n";
        }
    }


    return 0;
}