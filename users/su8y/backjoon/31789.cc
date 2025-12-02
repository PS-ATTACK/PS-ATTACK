#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int main(){
    int n, s, t;
    cin >> n;
    cin >> s >> t;
    int c, w;
    for(int i=0; i<n; i++){
        cin >> c >> w;
        if(c <= s) {
            if(w > t){
                cout << "YES" << endl;
                return 0;
            }
        }

    }
    cout << "NO" << endl;

    return 0;
}