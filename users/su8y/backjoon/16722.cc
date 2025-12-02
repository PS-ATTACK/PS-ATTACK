#include <bits/stdc++.h>

#define pii Pair<int, int>
#define pis Pair<int, string>
#define pdd Pair<double, double>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

#define PRECODE template<typename T1, typename T2> struct Pair{ T1 y; T2 x; };
PRECODE

using namespace std;

int n;
int dohung[9][3];
int score = 0;
set<int> hap;
set<int> result_hap;
map<string, int> strMap = {
        {"CIRCLE",   0},
        {"TRIANGLE", 1},
        {"SQUARE",   2},
        {"YELLOW",   0},
        {"RED",      1},
        {"BLUE",     2},
        {"GRAY",     0},
        {"WHITE",    1},
        {"BLACK",    2},
};


bool Hap(vector<int>);

bool Gul() {
    if (result_hap.size() == hap.size()) {
        return true;
    } else {
        return false;
    }
}

void dfs(set<int> &s, int index, vector<int> &selected) {
    if (selected.size() == 3) {
        if (Hap(selected))
            s.insert(selected[0] * 100 + selected[1] * 10 + selected[2]);
        return;
    }
    for (int i = index + 1; i <= 9; i++) {
        selected.push_back(i);
        dfs(s, i, selected);
        selected.pop_back();
    }
}

int main() {
    FAST_IO
    string str;
    for (int i = 0; i < 9; i++) {
        cin >> str;
        dohung[i][0] = strMap[str];
        cin >> str;
        dohung[i][1] = strMap[str];
        cin >> str;
        dohung[i][2] = strMap[str];
    }
    cin >> n;
    char ch;
    int a, b, c;
    bool onlyOne = true;

    vector<int> nums;
    dfs(result_hap, 0, nums);

    for (int i = 0; i < n; i++) {
        vector<int> input;
        cin >> ch;
        if (ch == 'H') {
            cin >> a >> b >> c;
            input.clear();
            input.push_back(a);
            input.push_back(b);
            input.push_back(c);
            sort(input.begin(), input.end());

            int key = input[0] * 100 + input[1] * 10 + input[2];

            if (Hap(input) && hap.find(key) == hap.end()) {
                score++;
                hap.insert(key);
            } else {
                score--;
            }
        } else if (ch == 'G') {
            if (Gul() && onlyOne) {
                onlyOne = false;
                score += 3;
            } else {
                score--;
            }
        }
    }

    cout << score << endl;


    return 0;
}

bool Hap(vector<int> input) {

    for (int i = 0; i < 3; i++) {// 도형, 배경, 색
        int cnt[3] = {0,};
        for (int j = 0; j < 3; j++) {
            int index = input[j] - 1; // 1부터 시작하기 때문에 -1 해준다.
            cnt[dohung[index][i]]++;
        }
        for (int j = 0; j < 3; j++) {
            if (cnt[j] == 2)return false;
        }
    }
    return true;
}