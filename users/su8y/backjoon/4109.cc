#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

#define ll long long
#define pii pair<int, int>
#define pss pair<string, string>


using namespace std;


int adjs[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
};

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        vector<string> map;
        string input;

        for (int i = 0; i < n; i++) {
            cin >> input;
            map.push_back(input);
        }

        vector<string> result;
        // sovle
        for (int i = 0; i < n; i++) {
            string result_string = "";
            for (int j = 0; j < m; j++) {
                if (map[i][j] == '.') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int next_i = i + adjs[k][0];
                        int next_j = j + adjs[k][1];
                        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m) {
                            if (map[next_i][next_j] == '*') {
                                cnt++;
                            }
                        }
                    }
                    result_string += to_string(cnt);
                } else {
                    result_string += "*";
                }
            }
            result.push_back(result_string);
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << endl;
        }
    }
    return 0;
}
