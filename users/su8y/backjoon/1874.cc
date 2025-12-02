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


void solve() {
    int n;
    cin >> n;
    vector<int> inputs(n, 0);
    stack<int> s;
    queue<int> store;
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
        store.push(i + 1);
    }
    string output;
    int p = 0;
    while (true) {
        if (s.size() > 0 && inputs[p] == s.top()) {
            output += "-\n";
            s.pop();
            p++;
            continue;
        }
        if(p == n || store.empty()) break;

        int front = store.front();
        store.pop();
        output += "+\n";

        s.push(front);
    }
    if( p != n) cout << "NO" << endl;
    else cout << output;

}

int main() {
    FAST_IO;
    solve();
    return 0;
}