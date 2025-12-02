#include <bits/stdc++.h>

#define pint pair<int, int>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

#define PRECODE template<typename T1, typename T2> struct Pair{ T1 y; T2 x; };
PRECODE

using namespace std;

int n, m;
int board[101][101];
vector<pint > cheses;

void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                cheses.emplace_back(i, j);
            }
        }
}


/*
 * 가장자리는 외부공기를뜻하는 4로처리한다.
 * 4를어떻게알아내냐면 union_find 알고리즘을사용한 부모자료구조를사용한다.
 * 그리고 각 치즈의위치를 순회하며 4와 맞닿은면이 2개이상이라면녹일준비를한다.
 * 녹이고난 뒤 해당위치+ 해당위치와 0으로시작하는(공기가유입가능한) 위치를4의 공통 분모로처리한다.
 */

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
void updateOutsideAir(int y,int x) {
    queue<pint> q;
    q.emplace(y, x);
    board[y][x] = 4; // 외부 공기 표시
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == 0) {
                board[ny][nx] = 4;  // 외부 공기 표시
                q.emplace(ny, nx);
            }
        }
    }
}
void Print(){
    cout << endl;
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
int main() {
    Input();
    updateOutsideAir(0,0);

    int z=0;

    while(!cheses.empty()) {
        // Print();
        vector<pint > deleted;
        vector<pint > live;
        for( auto[y,x] : cheses){
            int cnt = 0;
            /* 외부공기 개수 세기*/
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (board[ny][nx] == 4) cnt++;
            }
            if (cnt >= 2){
                deleted.push_back({y,x});
            }
            else
                live.push_back({y,x});
        }
        if(deleted.empty()) break;

        for(auto [y,x] :deleted){
            board[y][x] = 4;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] == 0) {
                    updateOutsideAir(ny,nx);
                }
            }
        }

        cheses = live;
        z++;
    }
    cout << z;

    return 0;
}