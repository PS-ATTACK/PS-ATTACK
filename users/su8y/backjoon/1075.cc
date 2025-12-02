#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N,F;
    cin >> N >> F;
    N = N - (N % 100);// 두자리수 구하기
    for(int i = 0; i < 100; i++){
        if ((N + i) % F == 0) {
            printf("%02d\n",i); 
            break;
        }
    }
    return 0;
    
}