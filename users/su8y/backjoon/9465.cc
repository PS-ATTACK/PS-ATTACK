#include <bits/stdc++.h>

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define PRECODE typedef struct { int y;int x; } PAIR;
PRECODE

using namespace std;
int k, n;
int board[100001][2];
int dp[100001][2];

int main() {
    FAST_IO
    cin >> k;
    while (k-- > 0) {
        cin >> n;
        for (int i = 0; i < n * 2; i++) {
            cin >> board[i % n][i / n];
        }

        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = board[0][0];
        dp[1][1] = board[0][1]; // board 는 0부터 시작하지만 dp는 1부터 시작한다.
       
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                int nj = (j + 1) % 2;
                int maxDp_2 = max(dp[i - 2][0], dp[i - 2][1]);

                dp[i][j] = max(dp[i - 1][nj], maxDp_2) + board[i - 1][j]; // board는 0부터시작하기 때문
            }
        }
        cout << max(dp[n][0], dp[n][1]) << endl;


    }

    return 0;
}
