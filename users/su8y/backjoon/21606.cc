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
int inside[10000];

int dfs(int v, vector<vector<int>> &graph, vector<bool> visit) {
    int ret =0;

    int len = graph[v].size();
    for (int i = 0; i < len; i++) {
        int nv = graph[v][i];
        if(visit[nv]) continue;
        if(inside[nv]) {
            ret += 1;
            continue;
        }

        visit[nv] = true;
        ret += dfs(nv, graph, visit);
        visit[nv] = false;

    }
    return ret;

}
int dfsAll(vector<vector<int>> &graph) {
    vector<bool> visit(n,false);
    int total= 0;
    for(int i=0;i<n;i++) {
        if(inside[i] == 1) {
            visit[i] = true;
            total += dfs(i,graph,visit);
            visit[i] = false;

        }
    }
    return total;


}

int main() {
    cin >> n;
    vector<vector<int>> graph(n,vector<int>());

    string str;
    cin >> str;
    for(int i = 0 ; i < n;i++) {
        if(str[i] == '1') inside[i] = 1;
    }

    int a,b;
    for(int i = 0 ; i < n-1;i++) {
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << dfsAll(graph) << endl;

    return 0;
}
