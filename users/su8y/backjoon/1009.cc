#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T,a,b;
    ll result;
    cin >> T;

    while(T--){
        cin >> a >> b;
        if (b % 4 ==0) b = 4;
        else b %= 4;
        result = pow(a,b);
        if(result % 10 == 0) cout << 10 << "\n";
        else cout << result % 10 << "\n";
    } 
    return 0;
}