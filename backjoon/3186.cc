#include <bits/stdc++.h>
#define endl '\n'
#define fastio cin.tie(0)->sync_with_stdio(0)


using namespace std;

int k, l, n;
int main(){
    fastio;
    cin >> k >> l >> n;
    string arr;

    cin >> arr;

    int cnt_k=0, cnt_l=0, flag=0;
    bool isOutput = false;

    int i = 0;
    while(i < n){
        if(arr[i] == '1' && !flag) {
            cnt_k++;
        }else if( arr[i] == '0' && !flag){
            cnt_k = 0;
        }else if( arr[i] == '0' && flag ){
            cnt_l++;
        } else if ( arr[i] == '1' && flag){
            cnt_l=0;
        }
        if(cnt_k == k) {
            flag = 1;
        }
        if(cnt_l >= l) {
            isOutput = true;
            cout << i+1 << endl;
            cnt_k = 0;
            cnt_l = 0;
            flag = 0;
        }
        i++;
    }

    if(flag == 1){
        isOutput = true;
        cout << i - cnt_l + l  << endl;
    }


    if(!isOutput) cout << "NIKAD" << endl;

    return 0;
}