#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);


using namespace std;


int a, b, c;

void solve() {
    cin >> a
        >> b
        >> c;
    cout << a + b - c << endl;
    cout << atoi((to_string(a) + to_string(b)).c_str()) - c << endl;
}


int main() {
    FAST_IO;
    solve();
    return 0;
}