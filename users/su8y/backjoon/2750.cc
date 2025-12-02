#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
int a[1001];

int abs(int a){
    if(a < 0)
        return -(a);
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr1;
    vector<int>::iterator iter;
    int tmp;
    cin >> n;
    for(int i = 0; i<n; ++i){
        cin >>tmp ;
        arr1.emplace_back(tmp);
        //cin >> arr1[i];
    }
    sort(arr1.begin(),arr1.end());
    
    for(iter = arr1.begin(); iter != arr1.end(); iter++){
        cout << *iter << endl;
    }
    return 0;
}