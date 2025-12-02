#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n,m,temp; // 박스 책 용량
    cin >> n >> m;
    vector<int> box;
    
    while(n--){ cin >> temp; box.push_back(temp);}

    for(int i=0; i<m; i++){
        cin >> temp;
        for (auto &elem : box) {
            if (elem >= temp) {
                elem -= temp;
                break;
            }
        }
    }
    int sum=0;
    for(const auto &elem : box){
       sum += elem; 
    }
    cout << sum;
    return 0;
}