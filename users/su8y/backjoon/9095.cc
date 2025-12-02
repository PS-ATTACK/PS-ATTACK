//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t,input;
int dp(int input){
    if(input == 1) return 1;
    if(input == 2) return 2;
    if(input == 3) return 4;

    return (dp(input -1) + dp(input -2) + dp(input - 3)); 
}
void solve(){
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        cin >> input;
        cout << dp(input) << endl;
    }
    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << "Hello World" << endl;
    solve();
    return 0;
}
