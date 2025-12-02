#include <bits/stdc++.h>

#define pint pair<int, int>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

#define PRECODE template<typename T1, typename T2> struct Pair{ T1 y; T2 x; };
PRECODE

using namespace std;

int n;
vector<int> adjs[101];
int visited[101];

void dfs(int x){
    for(int i= 0 ; i < adjs[x].size(); i++){
        int nxt = adjs[x][i];
        if(visited[nxt]) continue;
        visited[nxt] = 1;
        dfs(nxt);
    }
    return;
}
void Input() {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 1) adjs[i].push_back(j);
        }

}


int main() {
    Input();

    for(int i = 0 ; i < n; i++){
        memset(visited, 0, sizeof visited);
        dfs(i);
        for (int j = 0; j < n; ++j) {
            cout << visited[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}