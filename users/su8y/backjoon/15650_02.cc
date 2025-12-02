//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n , m; 
bool visited[9];
// int arr[] = {0,1,2,3,4,5,6,7,8,9};
string arr = "123456789";
string res;
void solve();

void bt(int index, string res){
    if(index == n ){
        if(res.length() == m){
            for(auto i : res){
                cout << i << " ";
            }
        cout << endl;
        }
        return;
    }
    int num = arr[index];
    bt(index + 1, res + (char)num);
    bt(index + 1, res);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

void solve(){
    cin >> n >> m ;    //n = number m = 개수
    bt(0 ,res);
}