#include <bits/stdc++.h>

using namespace std;

#define MAX 100

#define pint pair<int,int>
int arr[2001];

    bool cmp(pint a ,pint b) {
        return a.first < b.first;

    }

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<pair<int,int>> v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v.push_back({a,i});
        v.push_back({b,i});
    }
    sort(v.begin(), v.end(),cmp);
    int cur = n % (m * 2);

    cout << v[cur-1].second + 1;

    return 0;
}
