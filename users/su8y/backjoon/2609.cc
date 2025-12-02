#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    //8:22
    int a,b;
int n_min,n_max;
    cin >> a >> b;
    
    n_max = lcm(a,b);
    n_min = gcd(a,b);
            cout << n_min <<"\n" << n_max <<endl;

} 
