#include <bits/stdc++.h>

#define vint vector<int>
#define pint pair<int,int>
#define FAST_IO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define PRECODE typedef struct { int y;int x; } PAIR;
PRECODE

using namespace std;

int n, m,t;
int a[100001];

void Input() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    Input();
    int total = 0;

    for(int i=0;i<n;i++){
        // bf 방식 1000 개의 전구에 대해서 2 * 1000의 연산 n^2
        int minValue = 999999;
        for(int j= a[i];j>=1;j--){
            if(t % j == 0) {
                minValue = min(abs(a[i] - j),minValue);
                break;
            }
        }
        for(int j= a[i];j <= t;j++){
            if(t % j == 0) {
                minValue = min(abs(a[i] - j),minValue);
                break;
            }
        }
        total += minValue;
    }
    cout << total;

    return 0;
}
