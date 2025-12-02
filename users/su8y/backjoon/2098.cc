#include <bits/stdc++.h>

#define pint pair<int, int>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

using namespace std;

int n, m;
int dp[16][1 << 16];
int dist[16][16];
int INF = 987654321;

int dfs(int cur, int visit) {
    int &ret = dp[cur][visit];
    if (visit == ((1 << n) - 1)) return dist[cur][0] == 0 ? INF : dist[cur][0];
    if (ret != -1) return ret;

    ret = INF;

    for (int i = 0; i < n; i++) {
        if (dist[cur][i]  == 0) continue;
        if ((visit & (1 << i)) == (1 << i)) continue;
        ret = min(ret, dist[cur][i] + dfs(i, visit | (1 << i)));
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j]; // 정점 i에서 j로 가는 비용
        }
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 1);
    return 0;
}