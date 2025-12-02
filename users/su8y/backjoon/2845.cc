#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define ll long long

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int L,P;
    int N_p;
    cin >> L >> P;
    for(int i=0; i<5; i++){
        cin >> N_p;
        cout << N_p -(L*P) << " ";
    }
    cout << "\n";
    return 0;
}