#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
// #define swap(x,y,t) ((t=y),(y=x),(x=t))

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N,K;
    vector<int> arr;
    scanf("%d %d", &N , &K);

    for(auto i=1; i<=N; i++){
        arr.push_back(i);
    }
    int count = 0;
    for(int i = N; i>=0; i--){
        if(K == 0) break;
        if(K - (i-1) >= 0){ // ex 2 - 2 : 3 1 2 4
            arr.erase(arr.begin()+i-1+count);
            arr.insert(arr.begin() + count,i);
            K -= i -1;
            count++;
        }        
    }
    // arr.erase(arr.begin()+2);
    // arr.insert(arr.begin(),3);

    for(auto elem : arr){
        cout << elem << " ";
    }
    cout << "\n";
    return 0;
}