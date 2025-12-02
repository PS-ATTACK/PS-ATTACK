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


int T, N, M, K;
string s;
int n;

int main() {
    FAST;
    cin >> T;
    while (T--) {
        multiset<int> ms;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> s >> n;
            if (s == "I") {
                ms.insert(n);
                continue;
            }
            if(ms.empty()) continue;
            if (n == 1)ms.erase(--ms.end());
            else ms.erase(ms.begin());
        }
        if(ms.size() ==0) cout << "EMPTY" << endl;
        else cout << *--ms.end() << " "<< *ms.begin() << endl;
    }


    return 0;
}

