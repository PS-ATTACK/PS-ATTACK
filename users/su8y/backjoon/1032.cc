#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    vector<string> str;
    vector<string> answer;
    string tmp;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        if(i == t-1){ answer.push_back(tmp);
        break; }
        str.push_back(tmp);
    }

    tmp.clear();

    for (int j = 0; j < t - 1; j++) {
        for (int i = 0; i < answer[0].length(); i++) {
            char c = answer[0][i];
            if (c != str[j][i])
                tmp += '?';
            else
                tmp += c;
        }
        answer[0] = tmp;
        tmp.clear();
    }
    cout << answer[0] << endl; 
    return 0;
}