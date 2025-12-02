#include <bits/stdc++.h>

using namespace std;

#define MAX 100

#define pint pair<int,int>
#define vint vector<int>

char graph[6][6];
int vst[6][6];
int r, c, k;
int count = 0;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int dfs(int y, int x, int d) {
    int total = 0;
    if (y == 0 && x == c - 1) {
        if (d == k) {
            return 1;
        }
        return 0;
    }
    if (d >= k) return 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c ||
            graph[ny][nx] == 'T' ||
            vst[ny][nx])
            continue;
        vst[ny][nx] = 1;
        total += dfs(ny, nx, d + 1);
        vst[ny][nx] = 0;
    }

    return total;
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }
    vst[r - 1][0] = 1;
    cout << dfs(r - 1, 0, 1);

    return 0;
}
