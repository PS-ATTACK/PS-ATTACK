#include <bits/stdc++.h>

#define ll long long
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

using namespace std;
int R, C;
vvc graph;

vector<pii > ab;
vector<vector<pii>> roots;
queue<pair<int, pii>> ices;


int dirs[4][2] = {{0,  1},
                  {0,  -1},
                  {1,  0},
                  {-1, 0}};

pii find(pii yx) {
    if (roots[yx.first][yx.second] == yx) return yx;
    return roots[yx.first][yx.second] = find(roots[yx.first][yx.second]);
}

void m_union(pii a, pii b) {
    pii yx1 = find(a);
    pii yx2 = find(b);
    if (yx1 == yx2) return;

    if (yx1.first <= yx2.first || yx1.second <= yx1.second) {
        roots[yx2.first][yx2.second] = roots[yx1.first][yx1.second];
    } else {
        roots[yx1.first][yx1.second] = roots[yx2.first][yx2.second];
    }
}


bool is_valid(int y, int x) {
    return y >= 0 && y < R && x >= 0 && x < C;
}

bool can_meet() {
    queue<pii > q;
    vector<vector<bool>> visited(R, vector<bool>(C));
    q.emplace(ab[0]);
    visited[ab[0].first][ab[0].second] = true;

    while (!q.empty()) {
        pii front = q.front();
        if (front == ab[1]) return true; // success case
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nxt_y = front.first + dirs[i][0];
            int nxt_x = front.second + dirs[i][1];

            if (is_valid(nxt_y, nxt_x) &&
                graph[nxt_y][nxt_x] != 'X' &&
                visited[nxt_y][nxt_x] == false) {

                q.emplace(nxt_y, nxt_x);
                visited[nxt_y][nxt_x] = true;
            }
        }

    }
    return false;
}

bool can_meet2() {
    return find(ab[0]) == find(ab[1]);
}

void warm(int i) {
    while (!ices.empty()) {
        pair<int, pii > f = ices.front();
        pii front = f.second;
        if (f.first != i) return;
        ices.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = front.first + dirs[i][0];
            int next_x = front.second + dirs[i][1];
            if (is_valid(next_y, next_x)) {
                if (graph[next_y][next_x] == 'X') {
                    graph[next_y][next_x] = '.';
                    ices.push({f.first + 1, {next_y, next_x}});
                }
                m_union({front.first, front.second}, {next_y, next_x});
                for (int i = 0; i < 4; i++) {
                    int n_y = next_y + dirs[i][0];
                    int n_x = next_x + dirs[i][1];
                    if (is_valid(n_y, n_x) && graph[n_y][n_x] != 'X')
                        m_union({front.first, front.second}, {n_y, n_x});
                }
            }
        }
    }


}

void setup(pii yx) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<pii > q;
    q.push(yx);
    visited[yx.first][yx.second] = true;

    while (!q.empty()) {
        pii f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_y = f.first + dirs[i][0];
            int next_x = f.second + dirs[i][1];
            if (is_valid(next_y, next_x) && graph[next_y][next_x] != 'X' && !visited[next_y][next_x]) {
                m_union({f.first, f.second}, {next_y, next_x});
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }

    }

}

int main() {
    FAST_IO
    cin >> R >> C;

    graph.resize(R, vector<char>(C, 0));
    roots.resize(R, vector<pii >(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            roots[i][j] = {i, j};
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'L') {
                ab.emplace_back(i, j);
            }
            if (graph[i][j] != 'X') {
                ices.push({0, {i, j}});
            }
        }
    }

    setup(ab[0]);
    setup(ab[1]);
    if (can_meet()) {
        cout << 0 << "\n";
        return 0;
    }
    int len = max(R, C);
    for (int i = 0; i < len; i++) {
//        cout << i << endl;
//        for(int j = 0 ; j < 60; j++){
//            for(int k = 0 ; k < 60 ;k ++){
//                cout << graph[j][k];
//            }
//            cout <<endl;
//        }
        warm(i);
        if (can_meet2()) {
            cout << i + 1 << "\n";
            return 0;
        }

    }


    return 0;
}
