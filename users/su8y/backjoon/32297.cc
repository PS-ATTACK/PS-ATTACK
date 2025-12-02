#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>


#define FAST_IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define pii pair<int, int>

using namespace std;


int main() {
    FAST_IO
    int n;
    string str;
    cin >> n;
    cin >> str;
    if (str.find("gori") != string::npos) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}
