#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int main() {
    vector<int> arr1;
    vector<int>::iterator iter;
    int tmp;
    int sum_time=0;
    int buffer=0;
    cin >> n;

    for(int i = 0; i<n; ++i){
        cin >>tmp ;
        arr1.emplace_back(tmp);
        //cin >> arr1[i];
    }
    sort(arr1.begin(),arr1.end());

    for(iter = arr1.begin(); iter != arr1.end(); iter++){
        sum_time += *iter + buffer;
        
        buffer += *iter;
    }

    cout << sum_time <<endl;
    return 0;
}