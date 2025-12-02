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
#define pii pair<int,int>
#define pss pair<string,string>

using namespace std;

int N, M, K, X;

bool cmp(const pii &a, const pii &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;

}

int main() {
    FAST_IO
    cin >> N;

    vector<pii > v;

    int s, e;
    for (int i = 0; i < N; ++i) {
        cin >> s >> e;
        v.emplace_back(s, e);
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    int n_last_end = 0;
    for (int i = 0; i < N; i++) {
        if (n_last_end <= v[i].first) {
            cnt++;
            n_last_end = v[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}