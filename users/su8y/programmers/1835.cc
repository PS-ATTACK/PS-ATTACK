#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    string s = "ACFJMNRT";
    sort(s.begin(), s.end());
    
    do {
        bool b = true;
        for(auto &c: data) {
            int st = s.find(c[0]);
            int ed = s.find(c[2]);
            
            char op = c[3];
            int x = c[4]-'0';
            
            int len = abs(st - ed) - 1;
            if(op == '=') {
                if(len == x) { }
                else b = false;
            } else if (op == '<') {
                if(len < x) {
                } else b = false;
            } else {
                if(len > x) {
                } else b = false;
            }
        }
        if(b) answer++;
        
    } while(next_permutation(s.begin(), s.end()));
    
    
    
    return answer;
}
