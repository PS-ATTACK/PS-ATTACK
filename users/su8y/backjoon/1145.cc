#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    int D_a = 101; 
    int arr[5];
    for(int i=0;i<5;i++){
        cin >> arr[i];
        if(arr[i] < D_a) D_a = arr[i]; 
    }
    while(1){
        int count = 0;

        for (int i = 0; i < 5; i++) {
            if (D_a % arr[i] == 0) {
                count++;
            }
        }
        if (count >= 3) break;
        else D_a++;
    }
    cout << D_a << "\n";
}