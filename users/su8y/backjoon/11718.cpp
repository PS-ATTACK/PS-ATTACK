//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    vector<string> s;
    string str;
    while(getline(cin,str)){
        s.push_back(str);
    }
    for (auto &&i : s){
        cout << i << endl;
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
