#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>


#define ll long long
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>

using namespace std;
int N, K, L;
const int snake = 'x';
vvi graph; // 사과는 1
queue<pii > snake_dir_chg; // 0 left , 1 right
int dirs[4][2] = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0}
};
int snake_dir = 0; // 0이 오른쪽
deque<pii > snake_position_stack; // tail front ,  head top

void rotate() {
    snake_dir = (snake_dir + 1 + 4) % 4;
}

void r_rotate() {
    snake_dir = (snake_dir - 1 + 4) % 4;
}

bool check(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

void snake_tail_move() {
    pii tail_info = snake_position_stack.front();
    snake_position_stack.pop_front();
    graph[tail_info.first][tail_info.second] = 0;
}

int snake_head_move()/* return program exit flag */ {
    pii head_info = snake_position_stack.back();

    int ret = 0;

    int next_y = head_info.first + dirs[snake_dir][0];
    int next_x = head_info.second + dirs[snake_dir][1];

    if (!check(next_y, next_x) || graph[next_y][next_x] == snake) {
        return -1;
    }
    if (graph[next_y][next_x] == 1) ret = 1; // 사과

    graph[next_y][next_x] = snake;
    snake_position_stack.emplace_back(next_y, next_x);
    return ret;
}

void snake_change_dir(int minutes) {
    if (!snake_dir_chg.empty()) {
        pii chg = snake_dir_chg.front();
        if (chg.first == minutes) {
            snake_dir_chg.pop();
            if (chg.second == 'D') {
                rotate();
            } else {
                r_rotate();
            }
        }
    }
}


void print_graph() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] == snake) cout << (char) snake;
            else cout << graph[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin >> N
        >> K;
    graph.resize(N, vector<int>(N, 0));
    int x, y;

    for (int i = 0; i < K; ++i) {
        cin >> y >> x;
        graph[y - 1][x - 1] = 1;
    }
    cin >> L;
    int a; // a초후 b방향으로 90도 회전
    char b;
    for (int i = 0; i < L; i++) {
        cin >> a >> b;
        snake_dir_chg.emplace(a, b);
    }
    snake_position_stack.emplace_back(0, 0);
    graph[0][0] = snake;

    for (int i = 1; i <= 100000; i++) {
        int res = snake_head_move();


        if (res == -1) {
            cout << i << endl;
            return 0;
        }

        if (res == 0) snake_tail_move();

        snake_change_dir(i);

//        cout << "__________________" << i << " " << res << "________\n";
//        print_graph();
    }


    return 0;
}
