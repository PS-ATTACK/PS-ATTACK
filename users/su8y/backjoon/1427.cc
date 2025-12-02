#include <bits/stdc++.h>

#define pint pair<int, int>
#define vvi vector<vector<int>>
#define FAST_IO cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);

using namespace std;

int n;


int main() {
    string s;
    cin >> s;
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < s.size(); i++) {
        cout << v[i];
    }


    return 0;
}
