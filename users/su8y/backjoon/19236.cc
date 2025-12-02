#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

#define ll long long
#define pii pair<int, int>
#define pss pair<string, string>

/*
 *  1. 0.0 에서시작 , 해당물고기의방향을얻는다 .
 *  2. 물고기는작은번호부터움직이기시작,한칸이동, 다른물고기가있는칸으로이동가능 , 이동할수없다면45도회전을계속한다.
 *  3. 물고기가서로있다면위치를바꾼다 .
 */

using namespace std;

vector<vector<int> > copy(vector<vector<int> > &v) {
    vector<vector<int> > result;
    for (int i = 0; i < v.size(); i++) {
        result.push_back(vector<int>(v[i]));
    }
    return result;
}

int N = 4, M = 4;
vector<vector<int> > fish_dir(4, vector<int>(4));
vector<vector<int> > fishs(4, vector<int>(4));


int dirs[8][2] = {
    {-1, 0}, /* top */
    {-1, -1}, /* left-top */
    {0, -1}, /* left */
    {1, -1}, /* left-bottom */
    {1, 0}, /*bottom*/
    {1, 1}, /* right-bottom */
    {0, 1}, /* right */
    {-1, 1}, /* right-top*/
};

int rotaion_dir(int x) {
    int rotate_x = x + 1;
    return rotate_x % 8;
}


bool valid_out_of_bounds(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

bool valid_fish_move(int y, int x) {
    return valid_out_of_bounds(y, x) &&
           fishs[y][x] != -1;
}

/*
 * -1 이동불가능  index out of bounds
 * 0  이상의숫자  위치를 바꿔야 할 물고기 번호
 */

int shark_dir;
vector<pii > fish_location(17);
/* x번의 피쉬를 이동한다.*/
void swap_location(int a, int b) {
    /* swap dir */
    int a_y = fish_location[a].first;
    int a_x = fish_location[a].second;
    int b_y = fish_location[b].first;
    int b_x = fish_location[b].second;

    int tmp = fish_dir[a_y][a_x];
    int b_dir = fish_dir[b_y][b_x];
    fish_dir[a_y][a_x] = b_dir;
    fish_dir[b_y][b_x] = tmp;

    /* location */
    pii temp = pii(fish_location[a]);
    fish_location[a] = pii(fish_location[b]);
    fish_location[b] = temp;

    /* fish */
    fishs[a_y][a_x] = b;
    fishs[b_y][b_x] = a;
}

bool alive_fish(int x) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (fishs[i][j] == x) return true;
        }
    }
    return false;
}

void move_fish(int prev_x, int prev_y, int x, int y, int n) {
    fishs[prev_y][prev_x] = 0;
    fishs[y][x] = n;

    fish_location[n] = {y, x};

    int origin_dir = fish_dir[prev_y][prev_x];
    fish_dir[prev_y][prev_x] = 0;
    fish_dir[y][x] = origin_dir;
}

int move(int x) {
    if (!alive_fish(x)) return -1;
    while (true) {
        int location_y = fish_location[x].first;
        int location_x = fish_location[x].second;

        int n_dir = fish_dir[location_y][location_x];

        int next_y = location_y + dirs[n_dir][0];
        int next_x = location_x + dirs[n_dir][1];

        if (valid_fish_move(next_y, next_x)) {
            int other_fish;
            if ((other_fish = fishs[next_y][next_x]) > 0) {
                swap_location(other_fish, x);
            } else {
                move_fish(location_x, location_y, next_x, next_y, x);
            }
            break;
        }
        // 방향 회전
        int rotate_dir = rotaion_dir(n_dir);
        fish_dir[location_y][location_x] = rotate_dir;
    }
    return 0;
}

static int max_value = 0;

int full_move() {
    for (int i = 1; i <= 16; i++) {
        move(i);
    }
    return 0;
}

int eat_fish(int y, int x, int next_y, int next_x) {
    fishs[next_y][next_x] = -1;
    if (y != -1 && x != -1)
        fishs[y][x] = 0;
    return fish_dir[next_y][next_x];
}


void solve(int y, int x, int dir, int n_points) {
    vector<vector<int> > prev_fish = copy(fishs);
    vector<vector<int> > prev_fish_dir = copy(fish_dir);
    vector<pii > prev_fish_location = vector<pii >(fish_location);
    full_move();
    for (int i = 1; i <= 3; i++) {
        int next_y = (dirs[dir][0] * i) + y;
        int next_x = (dirs[dir][1] * i) + x;
        if (valid_out_of_bounds(next_y, next_x)) {
            int n_fish;
            if ((n_fish = fishs[next_y][next_x]) > 0) {
                /* process */
                int eat_dir = eat_fish(y, x, next_y, next_x);

                solve(next_y, next_x, eat_dir, n_points + n_fish); // n_fish + 1
                fishs[y][x] = -1;
                fishs[next_y][next_x] = n_fish;
            }
        } else break;
    }
    fishs = prev_fish;
    fish_dir = prev_fish_dir;
    fish_location = prev_fish_location;
    max_value = max(max_value, n_points);
}


int main() {
    int a, b;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b; /* 번호, 방향*/
            fish_dir[i][j] = b - 1;
            fishs[i][j] = a;
            fish_location[a] = pii(i, j);
        }
    }

    int n_fish = fishs[0][0];
    int eat_dir = eat_fish(-1, -1, 0, 0);
    solve(0, 0, eat_dir, n_fish);
    cout << max_value << endl;;
}
