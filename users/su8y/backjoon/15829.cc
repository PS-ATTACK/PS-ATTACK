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


ll N, M = 1234567891L;
ll r = 31;

int main() {
    FAST_IO
    string s;
    cin >> N;
    cin >> s;
    ll H = 0;
    for (int i = 0; i < N; i++) {
        unsigned ll n = (s[i] - 'a') + 1; /* 1부터 시작 */
        unsigned ll p = pow(r, i);
        H += (n * p) % M;
    }
    cout << H << endl;


    return 0;
}