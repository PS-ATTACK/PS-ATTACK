#include <iostream>
#include <string>
using namespace std;
char c[6] = "piird";
int main(){
    string str;
    bool iscmp = 1;
    cin >> str;
    int len = str.length();
    for(int i = 0; i < 5;i++){
        if(str[len - i-1] != c[i]){
            iscmp = 0;
        }
    }
    iscmp == 1 ? cout << "cute" : cout << "not cute";
    return 0;
}