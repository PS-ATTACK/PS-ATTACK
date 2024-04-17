#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);


using namespace std;



void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> result;
    int yosefuse[n];
    for (int i = 0; i < n; ++i) yosefuse[i] = i;

    int cur = 1;
    int i = 0;
    while(result.size() < n){
        if(i >=n ) i %= n;
        if(yosefuse[i] != -1){
            if(cur == k){
                result.push_back(yosefuse[i] + 1);
                yosefuse[i] = -1;
                cur =0;
            }
            cur++;
        }
        i++;
    }
    cout << "<";
    for(int i = 0; i < n;i++){
        if(i != 0){
            cout << " ";
        }
        cout <<result[i];
        if(i != n -1){
            cout << ",";
        }
    }
    cout << ">";



}

int main() {
    FAST_IO;
    solve();
    return 0;
}