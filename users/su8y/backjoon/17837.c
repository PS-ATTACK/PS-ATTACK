#include <bits/stdc++.h>

using namespace std;

#define MAX 100
// r,u,l,d
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int n, k;

int g_board[13][13]; // 타일 색깔
pair<pair<int, int>, int> pieceInfo[11]; // 말 정보
vector<int> piece[13][13];

int m_dirMapping(int x) {
    switch (x) {
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
    }
}

/*
 * 0 white
 * 1red
 * 2 blue
 * */
int m_getColorFromTile(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n) return 2;
    return g_board[y][x];
}

/*
 * 1. 말 위에 다른말을 올릴 수 있다.  (4개이상쌓이는순간게임은종료된다.)
 * 2.말의이동방향은정해져있다. ( 움직이는 발판에따라서이동방향이변경될수 있다.)
 * 3. 1-> N번말까지이동한다.
 * rIncreaseFontSize)
 * 4. 흰색: 그 위에 올려놓는다.  XYZ가존재하면  XYZAB
 * 4. 빨강: 움직이는 말을  반대로하고 그 위에 올려놓는다.  XYZ가존재하면  XYZBA
 * 6. 파랑, 경계지점: 이동방향을 반대로하고 한칸 이동한다. 단 이동하려는칸이 똑같은성질이면 가만히있는다.
 */
void m_moveWhite(int y, int x, int ny, int nx, int num) {
    //position, pieces
    // 1. 이동할 말의 윗부분을 찾는다.
    vector<int> pieces = piece[y][x];
    // 2. 말 의존관계에서 윗부분(엎고있는)부분집합을구한다. 그와동시에 원래부분 집합을없앤다.
    vector<int> slice;

    auto idx = find(pieces.begin(), pieces.end(), num) - pieces.begin();

    slice.insert(slice.begin(), pieces.begin() + idx, pieces.end());
    piece[y][x].assign(piece[y][x].begin(), piece[y][x].begin() + idx);

    // 3.모두움직였다면 없애준다.
    // 3-1 . 움직여준다.
    for (int i = 0; i < slice.size(); i++) {
        int movedPiece = slice[i];
        pieceInfo[movedPiece].first.first = ny;
        pieceInfo[movedPiece].first.second = nx;
    }

    // 3-2타겟 바닥말에게 의존관계를이어준다.
    piece[ny][nx].insert(piece[ny][nx].end(), slice.begin(), slice.end());
}

// 이동할 위치
void m_moveRed(int y, int x, int ny, int nx, int num) {
    //position, pieces
    // 1. 이동할 말의 윗부분을 찾는다.
    vector<int> pieces = piece[y][x];
    // 2. 말 의존관계에서 윗부분(엎고있는)부분집합을구한다. 그와동시에 원래부분 집합을없앤다.
    vector<int> slice;

    auto idx = find(pieces.begin(), pieces.end(), num) - pieces.begin();

    slice.insert(slice.begin(), pieces.begin() + idx, pieces.end());
    piece[y][x].assign(piece[y][x].begin(), piece[y][x].begin() + idx);

    reverse(slice.begin(), slice.end());
    // 3.모두움직였다면 없애준다.
    // 3-1 . 움직여준다.
    for (int i = 0; i < slice.size(); i++) {
        int movedPiece = slice[i];
        pieceInfo[movedPiece].first.first = ny;
        pieceInfo[movedPiece].first.second = nx;
    }
    // 3-2타겟 바닥말에게 의존관계를이어준다.
    piece[ny][nx].insert(piece[ny][nx].end(), slice.begin(), slice.end());
}

bool m_isEnd() {
    for (int i = 0; i < k; i++) {
        pair<int, int> yx = pieceInfo[i].first;
        if (piece[yx.first][yx.second].size() >= 4) return true;
    }
    return false;
}

void init() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            piece[i][j] = vector<int>();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g_board[i][j];
        }
    }

    int y, x, d;
    for (int i = 0; i < k; i++) {
        cin >> y >> x >> d;
        pieceInfo[i] = {{y - 1, x - 1}, m_dirMapping(d)};
        piece[y - 1][x - 1].push_back(i);
    }

    for (int z = 0; z < 1001; z++) {
        for (int i = 0; i < k; i++) {
            pair<pair<int, int>, int> &p = pieceInfo[i]; // yx , dir
            int ny = dy[p.second] + p.first.first;
            int nx = dx[p.second] + p.first.second;
            int color = m_getColorFromTile(ny, nx);

            if (color == 2) {
                p.second = (p.second + 2) % 4;
                ny = dy[p.second] + p.first.first;
                nx = dx[p.second] + p.first.second;
                color = m_getColorFromTile(ny, nx);
            }

            switch (color) {
                case 0:
                    m_moveWhite(p.first.first, p.first.second, ny, nx, i);
                    break;
                case 1:
                    m_moveRed(p.first.first, p.first.second, ny, nx, i);
                    break;
            }

            if (m_isEnd()) {
                cout << z + 1 << endl;
                return 0;
            }
        }
    }


    cout << "-1\n";
    return 0;
}
