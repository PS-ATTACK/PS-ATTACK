#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, p, c;
    string name;
    map<int, string> m1;
    map<int, string>::iterator iter;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p;
        for (int j = 0; j < p; ++j) {
            cin >> c >> name;
            m1.insert(pair<int, string>(c, name));
        }
        if (m1.size() == 0) cout << "what!";
        iter = m1.end();// iter 의 원소 맨끝으로 함 end() 는 마지막원소가 아닌 쓰레기값 
        iter--; // 그렇기 때문에 iter을 하나 빼줌
        cout << iter->second << endl;
        m1.clear();//map 초기화
    }
    return 0;
}