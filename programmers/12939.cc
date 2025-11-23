#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream is(s);

    int mn = 1e9;
    int mx = -1e9;
    string buf;
    while(getline(is, buf, ' ')){
        int x= stoi(buf);
        mn = min(mn, x);
        mx = max(mx, x);
    }
    answer = to_string(mn) + " " + to_string(mx);
    return answer;
}