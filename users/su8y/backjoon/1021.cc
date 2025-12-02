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

using namespace std;

int N, M;
static int cnt_f_call = 0;

int get_index(deque<int> dq, int x) {
    for (int i = 0; i < dq.size(); i++) {
        if (dq[i] == x) return i;
    }
    return -1;
}

void left_move(deque<int> &dq, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int f = dq.front();
        dq.pop_front();
        dq.push_back(f);
    }
}

void right_move(deque<int> &dq, int cnt) {
    for (int i = 0; i < cnt; i++) {
        int b = dq.back();
        dq.pop_back();
        dq.push_front(b);
    }
}

int main() {
    FAST_IO
    deque<int> dq;
    vector<int> inputs;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) { dq.push_back(i); }
    for (int i = 0, tmp; i < M; i++) {
        cin >> tmp;

        int index = get_index(dq, tmp);
        int mid = dq.size() / 2;
        if (index == 0) {

        } else if (index <= mid) {
            cnt_f_call += index;
            left_move(dq, index);
        } else {
            cnt_f_call += dq.size() - index;
            right_move(dq, dq.size() - index);
        }
        int f = dq.front();
        if (f != tmp) {
            cout << "INVALID DATA" << tmp << endl;
        }
        dq.pop_front();

        // left이동
    }
    cout << cnt_f_call << endl;

    return 0;
}