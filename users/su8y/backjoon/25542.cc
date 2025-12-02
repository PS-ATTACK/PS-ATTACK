#include <bits/stdc++.h>

#define ll long long
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>
#define vvb vector<vector<int>>
#define vvc vector<vector<char>>

using namespace std;


int N, L;
string strArr[21];
queue<string> q;

int main() {
    /* 20  20 400 */
    FAST_IO
    cin >> N >> L;


    for (int i = 0; i < N; i++) {
        cin >> strArr[i];
    }
    q.push(strArr[0]);
    for (int i = 1; i < N; i++) {
        string target = strArr[i];
        int len = q.size();
        for (int j = 0; j < len; j++) { // similar strings
            vector<int> similar;
            string s = q.front();
            q.pop();
            //** somethings
            for (int k = 0; k < L; k++) {
                if (target[k] != s[k]) {
                    similar.emplace_back(k);
                }
            }

            int lenSimilar = similar.size();
            if (lenSimilar == 2) {
                char tmp;
                tmp = target[similar[0]];
                target[similar[0]] = s[similar[0]];
                q.push(target);
                target[similar[0]] = tmp;
                target[similar[1]] = s[similar[1]];
                q.push(target);
            } else if (lenSimilar < 2) {
                q.emplace(s);
            }

        }
    }
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        bool flag = true;
        for (int i = 0; i < N; i++) {
            string target = strArr[i];
            int cnt = 0;
            for (int k = 0; k < L; k++) {
                if (target[k] != s[k]) {
                    cnt++;
                }
            }
            if (cnt > 1) flag = false;
        }
        if (flag) {
            cout << s + '\n';
            return 0;
        }
    }

    cout << "CALL FRIEND\n";


    return 0;
}

