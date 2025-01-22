#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define ll long long

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    vector<int> real,b;
    real={1,1,2,2,2,8};
    for(int i=0; i<6; i++){
        cin >> n;
        b.push_back(n);
    } 

    for(int i=0; i<6; i++){
        cout << real[i] - b[i] << " ";
    }
    cout << "\n";
    return 0;
}