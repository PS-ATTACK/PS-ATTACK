#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);


using namespace std;
map<string, int> m;


int main() {
    FAST_IO
    int N;
    int sizes[6];
    int T, P;

    cin >> N;
    for (int & size : sizes) {
        cin >> size;
    }
    cin >> T >> P;


    int total_stock = 0;
    for (const int size : sizes) {
        /* 티셔츠 */
        int stock = size / T;
        if (size % T != 0) stock += 1;
        total_stock += stock;
    }
    /* pen */
    int cnt_pen_bundle = N / P;
    int cnt_pen = N % P;

    cout << total_stock << endl;
    cout << cnt_pen_bundle << " " << cnt_pen << endl;

    return 0;
}