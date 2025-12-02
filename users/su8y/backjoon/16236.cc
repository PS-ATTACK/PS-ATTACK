#include <bits/stdc++.h>

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define PRECODE typedef struct { int y;int x; } Pair;
PRECODE


using namespace std;

int n, m;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int board[21][21];
bool visited[21][21];
int sSize = 2;
int eatCount = 0;
Pair sYX;

/*
 * 자신보다 작은물고기 ( < )
 * 1. 가장 가까운 물고기
 * 2. 왼쪽 위부터
 * 3. 크기가 2라면 2개의 물고기먹으면 크기가 1 증가한다.
 */
int GetDistance(int, int);

void MoveShark(int, int);

int main() {
    FAST_IO
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sYX.y = i;
                sYX.x = j;
            }
        }
    }


    int time = 0;
    while (1) {
        int minDist = INT_MAX;
        int ny = -1;
        int nx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 9 || board[i][j] == 0) continue; // 자기자신
                if (board[i][j] >= sSize) continue; // 자기자신보다 크면

                int dist = GetDistance(i, j);
                if (minDist > dist) {
                    ny = i;
                    nx = j;
                    minDist = dist;
                }
            }
        }
        if (minDist == INT_MAX) {
            cout << time << endl;
            break;
        }
        MoveShark(ny, nx);
        time += minDist;

    }
    return 0;
}

bool IsOutOfRange(int y, int x) {
    return y < 0 || y >= n || x < 0 || x >= n;
}

struct cmp {
    bool operator()(pair<Pair, int> a, pair<Pair, int> b) {
        if (a.second == b.second) {
            if (a.first.y == b.first.y) {
                return a.first.x > b.first.x;
            }
            return a.first.y > b.first.y;
        }
        return a.second > b.second;
    }
};

int GetDistance(int y, int x) {
    memset(visited, false, sizeof visited);
    priority_queue<pair<Pair, int>, vector<pair<Pair, int>>, cmp> q; // yx, distance
    q.push({sYX, 0});
    visited[sYX.y][sYX.x] = true;

    while (!q.empty()) {
        auto f = q.top();
        q.pop();
        int nd = f.second + 1;

        for (int i = 0; i < 4; i++) {
            int ny = f.first.y + dy[i];
            int nx = f.first.x + dx[i];

            if (IsOutOfRange(ny, nx) || visited[ny][nx] || board[ny][nx] > sSize) continue;
            if (ny == y && nx == x) return nd;

            q.push({{ny, nx}, nd});
            visited[ny][nx] = true;
        }
    }


    return INT_MAX;
}

void MoveShark(int y, int x) {
    eatCount++;
    if (eatCount >= sSize) {
        eatCount = 0;
        sSize += 1;
    }
    board[sYX.y][sYX.x] = 0;
    board[y][x] = 9;
    sYX.y = y;
    sYX.x = x;
}
