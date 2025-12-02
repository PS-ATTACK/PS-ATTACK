#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define ll long long

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int A,I;
    cin >> A >> I;
    int ret = (A * (I-1)) + 1;
    cout << ret << "\n";
    return 0;
}