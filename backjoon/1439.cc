#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string str;
    static int count[2]={0,}; //구간이 다른곳을 카운트 해준다 .
    
    cin >> str;

    if(str[0] == '0'){
        count[0]++;
    }
    else count[1]++;

    for(int i=1; i <str.length();i++){
        if (str[i] != str[i - 1] && str[i] == '1') count[1]++;
        if (str[i] != str[i - 1] && str[i] == '0') count[0]++;
    }

    cout << min(count[0],count[1]) << "\n";
   
    return 0;
}