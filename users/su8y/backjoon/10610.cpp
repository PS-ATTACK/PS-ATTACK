#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int n = 0;
    string arrT;
    vector<int> arr;
    int isEven = 0;
    getline(cin,arrT);
    //문자 - > 숫자  문자 -'0'
    for(int i =0;i<arrT.size();i++){
        arr.push_back(arrT[i] - '0');
    }
    //내림차순 정렬
    sort(arr.rbegin(),arr.rend());
    //마지막숫자를 제외하여 isEven의 넣음
    for(int i =0;i<arr.size()-1;i++){
        isEven += arr[i];
    }
    if(isEven % 3 == 0 && arr[arr.size()-1] == 0){
        for(int i =0;i<arr.size();i++){
            cout << arr[i];
        }
        cout << endl;
    }
    else cout << -1 << endl;

}