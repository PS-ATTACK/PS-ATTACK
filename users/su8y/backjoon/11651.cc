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

int N, M, K, X;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    FAST_IO
    cin >> N;
    vector<pair<int, int>> v;

    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        v.emplace_back(x, y);
    }

    sort(v.begin(), v.end(), cmp);
    for (const auto &item: v) {
        printf("%d %d\n", item.first, item.second);

    }

    return 0;
}