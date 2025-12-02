#define ll long long

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 1 ; j < n - i; j++){
            printf(" ");
        }
        for(int j = n - i ; j <= n + i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;    
}