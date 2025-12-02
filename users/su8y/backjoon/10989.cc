#include <iostream>
#include <vector>
using namespace std;
int arr[10001];

int main()
{
    ios::sync_with_stdio(false);
    int max = 1;
    int n,a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        arr[a]++;
    }
    for(int i=1; i<10001; i++){
        if(arr[i] != 0){
            for(int j = arr[i]; j > 0;j--){
                cout << i << "\n";
            }
        }
        else continue;
    }
    return 0;
}