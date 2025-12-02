#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
string color[10] = {
    "black", "brown", "red", "orange", "yellow",
    "green", "blue", "violet", "grey", "white"
};
int main() {
    ios::sync_with_stdio(false);
    string str;
    ll result=0;
    //start
    cin >> str;
    for(int i=0;i<10;i++){
        if(str == color[i]) result += i * 10;
    }
    cin >> str;
    for(int i=0;i<10;i++){
        if(str == color[i]) result += i;
    }
    cin >> str;
    for(int i=0;i<10;i++){
        if (str == color[i])
            result *= pow(10,i);
    }
    cout << result <<"\n";

    return 0;
}