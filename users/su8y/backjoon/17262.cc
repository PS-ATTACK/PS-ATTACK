#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int s[n];
    int e[n];
    int s_max = 0;
    int e_min = 100001;

    for(int i=0;i<n;i++){
        cin >> s[i] >> e[i];
    }
    for(int i=0; i<n;i++){
        if(s[i] > s_max) s_max = s[i];
        if(e[i] < e_min) e_min = e[i];
    }
    if (s_max - e_min < 0) cout << 0 << "\n";
    else cout << s_max - e_min << "\n";
    return 0;
}