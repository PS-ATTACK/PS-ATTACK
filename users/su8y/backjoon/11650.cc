#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"


using namespace std;

bool m_compare(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;


}
int main() {
    FAST_IO
    int n;
    vector<pair<int,int> > v;

    cin >> n;
    int ia,ib;
    for (int i = 0; i < n; ++i) {
        cin >> ia >> ib;
        v.push_back({ia,ib});
    }

    sort(v.begin(), v.end(), m_compare);
    for (int i = 0; i < n; ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    }



    return 0;
}