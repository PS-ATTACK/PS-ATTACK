#include <iostream>
#include <vector>

using namespace std;
int n_sum(int n);
int main(){
    //8:14
    //8:14
    int n;
    cin >> n;
    cout << n_sum(n);
}
int n_sum(int n){
    static int sum = 0;
    for(int i = 1; i <= n; ++i){
    sum += i;
    }
    return sum;
    //8:17
}