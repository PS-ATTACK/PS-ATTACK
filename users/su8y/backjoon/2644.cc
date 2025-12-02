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

int T, N, M, K, a, b;
vector<vector<int> > arr;

bool visited[101];
int ret ;

int dfs(int n, int deps) {
    if (n == K) ret = deps;
    for (auto &v: arr[n]) {
        if (visited[v]) continue;
        visited[v] = true;
        dfs(v, deps + 1);
        visited[v] = false;
    }
    return 0;
}

int main() {
    FAST;
    cin >> N;
    arr.resize(N+1);

    cin >> a >> K;
    cin >> M;
    FOR(i, M) {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        arr[tmp].emplace_back(tmp1);
        arr[tmp1].emplace_back(tmp);
    }
    visited[a] = true;
    dfs(a, 0);
    if(ret == 0 ) cout << -1;
    else cout << ret;


    return 0;
}

