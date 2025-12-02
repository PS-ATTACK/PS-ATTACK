#include <iostream>
#include <vector>

using namespace std;

int main(){
    //8:19
    int n;

    cin >> n;
    for (int i =0; i < n; ++i){
        for(int j=0 ; j < n; ++j){
            if(j >=i)
                cout << "*";
            else 
                cout << " "; 
        }
        cout<<endl;

    }
    return 0;
    //8:21
}