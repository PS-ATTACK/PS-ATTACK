#include <bits/stdc++.h>

using namespace std;

#define LEN 8

const char target[2] = {'W', 'B'};

// ch { 0: black, 1: white }
int count(vector<string> &board, int st, int ed, int ch) {
    int count = 0;
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            if(board[i+st][j+ed] != target[ch]) count ++;
            ch = (ch + 1) % 2;
        }
        ch = (ch + 1) % 2; // 줄이 바뀌면서 색깔 변경
    }
    return count;
}

int main() {
    int n, m, ret = 50 * 50 + 1;
    vector<string> str;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        str.emplace_back(input);
    }

    /* n,m 크기의 8크기의 정사각형을 도는 경우 */
    for (int i = 0; i <= n - LEN; i++) {
        for (int j = 0; j <= m - LEN; j++) {
            int b = count(str, i,j,0);
            int w = count(str, i,j,1);
            int v =  min(b, w);
            ret = min(ret, v);
        }
    }
    cout << ret << endl;

    return 0;
}

