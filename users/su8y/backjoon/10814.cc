#include "bits/stdc++.h"

using namespace std;
#define ll long long;
#define endl "\n";

#ifdef BOJ
#define debug(x)  ((void)0)
#else
#define debug(x) std::cout << "[Debug] " << #x <<" is " << x << '\n'
#endif

int N;
vector<pair<int, string> > inputs;

bool cmp(const pair<int, string> a,
         const pair<int, string> b
) {
    return a.first < b.first;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    pair<int ,string> tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp.first >> tmp.second;
        inputs.push_back(tmp);
    }
    stable_sort(inputs.begin(), inputs.end(),cmp);
    for (int i = 0; i < inputs.size(); ++i) {
        cout<< inputs[i].first << " " << inputs[i].second<< endl;
    }

    return 0;
}


/**
*
5
21 A
21 a
21 Junkyu
21 Dohyun
20 Sunyoung
*/