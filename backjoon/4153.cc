#include "bits/stdc++.h"

using namespace std;
#define ll long long;
#define endl "\n";

#ifdef BOJ
#define debug(x)  ((void)0)
#else
#define debug(x) std::cout << "[Debug] " << #x <<" is " << x << '\n'
#endif

int arr[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        int a = pow(arr[0], 2);
        int b = pow(arr[1], 2);
        int c = pow(arr[2], 2);
        if (a == 0 && b == 0 && c == 0)return 0;
        if (a + b == c) printf("right\n"); else printf("wrong\n");

    }


    return 0;
}

