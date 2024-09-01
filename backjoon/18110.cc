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

#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt_trash = round((n * 0.3) / 2);

    int total = 0, tmp, cnt = 0;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i >= cnt_trash && i < n - cnt_trash) {
            total += v[i];
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return;
    }
    cout << (int) round(total / (double) cnt) << endl;

}


int main() {
    FAST_IO;
    solve();
    return 0;
}