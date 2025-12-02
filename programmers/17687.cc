/*
t*m의 n진수 문자열을 미리 만들고 결과를 만든다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const string nNum = "0123456789ABCDEF";

string Transform(int x, int n) {
    if(x == 0) return "0";
    string res = "";
    int num = x;
    while(num > 0) {
        res += nNum[num % n];
        num /= n;
    }
    reverse(res.begin(), res.end());

    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    stringstream prestr;
    for(int i=0; i<=t*m; i++) {
        prestr << Transform(i, n);
    }
    string str = prestr.str();
    
    for(int i=0; i<t; i++) {
        int order = (p-1);
        answer += str[ order + (m*i)];
        
    }

    return answer;
}

