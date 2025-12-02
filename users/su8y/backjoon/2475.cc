#include "bits/stdc++.h"

using namespace std;
#define ll long long;
#define endl "\n";

#ifdef BOJ
#define debug(x)  ((void)0)
#else
#define debug(x) std::cout << "[Debug] " << #x <<" is " << x << '\n'
#endif

int arr[5], sum = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 5; ++i){
        cin >> arr[i];

        sum += pow(arr[i],2);
    }
    cout << sum%10;


    return 0;
}

