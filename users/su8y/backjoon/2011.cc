#include <bits/stdc++.h>

#define ll long long
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

using namespace std;
string str;
vector<int> dp;

int dfs(string &s, int index) {
    int total = 0;
    if (index == s.length()) return 1;
    if (dp[index] != -1) return dp[index];


    for (int i = 1; i <= 2; i++) {
        if (index + i > s.size()) continue;
        string subStr = s.substr(index, i);
        if (subStr[0] == '0') continue;
        int num = stoi(subStr);
        if (num <= 26) {
            total += dfs(s, index + i);
        }
    }

    return dp[index] = total % 1000000;
}

int main() {
    FAST_IO
    cin >> str;

    dp.resize(str.size(), -1);
    dfs(str, 0);
    cout << dp[0] << endl;


    return 0;
}


