#include <bits/stdc++.h>

using namespace std;

#define MAX 100
int N, M;
int dirY[4] = {0, 0, 1, -1};
int dirX[4] = {1, -1, 0, 0};
vector<deque<int>> circle;
bool deleted[51][51];
bool g_deletedFlag;
int g_medium, g_mediumCnt;

void foo();

bool m_isValid(int y, int x) {
    return y >= 1 && y <= N && x >= 0 && x < M;
}


void deleteAdj(int y, int x) {
    if (circle[y][x] == 0) return;
    if (circle[y][x] != 0) {
        g_medium += circle[y][x];
        g_mediumCnt++;
    }

    for (int i = 0; i < 4; i++) {
        int nY = y + dirY[i];
        int nX = (x + dirX[i]) % M;

        if (!m_isValid(nY, nX)) continue;
        if (circle[y][x] == circle[nY][nX]) {
            deleted[nY][nX] = true;
            deleted[y][x] = true;
            g_deletedFlag = true;
//            circle[nY][nX] = true;
        }
    }
}

void m_rotate(int x, int c) {
    for (int i = 0; i < c; i++) {
        for (int k = 1; k * x < circle.size(); k++) {
            int b = circle[k * x].back();
            circle[k * x].pop_back();
            circle[k * x].emplace_front(b);
        }
    }
}

void m_reverseRotate(int x, int c) {
    for (int i = 0; i < c; i++) {
        for (int k = 1; k * x< circle.size(); k++) {
            int f = circle[k * x].front();
            circle[k * x].pop_front();
            circle[k * x].emplace_back(f);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> N >> M >> t;
    circle = vector<deque<int>>(N + 1, deque<int>(M));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> circle[i][j];
        }
    }
    int x, d, k;
    for (int z = 0; z < t; z++) {
        cin >> x >> d >> k;
        switch (d) {
            case 0:
                m_rotate(x, k);
                break;
            case 1:
                m_reverseRotate(x, k);
                break;
        }
        memset(deleted, false, sizeof(deleted));
        g_deletedFlag = false;
        g_medium = 0;
        g_mediumCnt = 0;

        for (int i = 1; i < N + 1; i++) {
            for (int j = 0; j < M; j++)
                deleteAdj(i, j);
        }

        if (g_deletedFlag) {
            for (int i = 1; i < N + 1; i++) {
                for (int j = 0; j < M; j++) {

                    if (deleted[i][j])
                        circle[i][j] = 0;
                }
            }
        } else {
            double mediumValue = (double) g_medium / (double) g_mediumCnt;
            for (int i = 1; i < N + 1; i++) {
                for (int j = 0; j < M; j++) {
                    if (circle[i][j] == 0) continue;
                    if (mediumValue > circle[i][j]) {
                        circle[i][j]++;
                    } else if (mediumValue < circle[i][j]) {
                        circle[i][j]--;
                    }
                }
            }
        }

//        foo();
    }

    int total = 0;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < M; j++) {
            total += circle[i][j];
        }

    }
    cout << total << '\n';


}

void foo() {
    cout << " PRINT " << endl;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < M; j++) {
            cout << circle[i][j] << ' ';
        }
        cout << endl;
    }
}
