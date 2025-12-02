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

#define pii pair<int, int>
#define pis pair<int, string>
#define pdd pair<double, double>
#define vvi vector<vector<int>>

using namespace std;
int N, K, L;


int main() {
    int total = 0;
    cin >> N;
    for (int i = 3; i--;) {
        cin >> K;
        if (K / N >= 1) {
            total += N;
        } else {
            total += K;
        }

    }
    cout << total << endl;

    return 0;
}
