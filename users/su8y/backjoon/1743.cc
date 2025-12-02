#include "bits/stdc++.h"

using namespace std;
#ifdef BOJ
#define debug(x)  ((void)0)
#define debugArr(c) ((void)0)
#else
#define debug(x) std::cout << "[DEBUG] " << #x <<" is " << x << '\n'
#define debugArr(c){ std::cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n';}
#endif
#define FOR(i, N) for(int i=0; i<N;i++)
#define FFOR(i, N) for(int i=1; i<=N;i++)
#define FORN(N) while(N--)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define ll long long
#define endl "\n"
typedef pair<int, int> pii;
#define MAX 101

int T, N, M, K, y, x;
int arr[MAX][MAX] = {0,};
bool visited[MAX][MAX];
int max_value = 0;
int deps=0;

int dirs[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
};

bool isVaild(int y, int x) {
    return 0 <= y && y <= N && x <= M && x >= 0 && arr[y][x] == 1 && !visited[y][x];
}

void solve(int y, int x) {
    visited[y][x] = true;
    deps++;
    for (int i = 0; i < 4; ++i) {
        int next_y = y + dirs[i][0];
        int next_x = x + dirs[i][1];
        if (isVaild(next_y, next_x)) {
            solve(next_y, next_x);
        }
    }

}

int main() {
    FAST;
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        cin >> y >> x;
        arr[y][x] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (arr[i][j] == 1 && !visited[i][j] ) {
                deps = 0;
                solve(i, j);
                max_value = max(max_value,deps);
            }

        }
    }
    cout << max_value;

    return 0;
}

