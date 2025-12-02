#include <bits/stdc++.h>

#define pint pair<int, int>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

#define PRECODE template<typename T1, typename T2> struct Pair{ T1 y; T2 x; };
PRECODE

using namespace std;
const int MAX = 101;
int cost[MAX];
bool visited[MAX];
int g[MAX][MAX];

int n, m, r;

void Input() {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    int a, b, w;
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> w;
        g[a][b] = w;
        g[b][a] = w;
    }
}

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int main() {
    Input();
    int max_total = INT_MIN;

    for(int i = 1 ; i <=n; i++){
        g[i][i] =0;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }


    for(int i=1; i<=n; i++){
        int total =0;
        for(int j=1; j<=n; j++){
            if(g[i][j] <= m){
                total += cost[j];
            }
        }
        if(total > max_total) max_total = total;
    }

    cout << max_total;

    return 0;
}