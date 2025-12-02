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

double calc_polygon_area(const vector<pii > &xy, int n) {
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        // abs 처리
        area += (xy[i].first + xy[j].first) * (long long) (xy[i].second - xy[j].second);
//        area += abs(xy[i].first * xy[j].second - xy[j].first * xy[i].second);
    }
    return abs((double) area / (double) 2.0);
}

int main() {
    FAST_IO
    cin >> N;

    vector<pii > v;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    double res_calc = round(calc_polygon_area(v, N) * 10)/ 10 ;
    printf("%.1f", res_calc);
}