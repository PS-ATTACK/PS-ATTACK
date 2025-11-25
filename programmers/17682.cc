#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

const string NUMBER = "0123456789";
int solution(string s) {
    int answer = 0;
    
    // base condition
    if(s.size() == 0) return 0;
    
    vector<int> v;
    v.push_back(0);
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])) {
            int ed = 1;
            while(isdigit(s[i + ed])) {
                ed++;
            }
            string ss = s.substr(i, ed);
            
            i += ed -1;
            v.push_back(stoi(ss));
            continue;
        }
        
        switch (s[i]) {
            case 'S': break;
            case 'D': 
                v[v.size()-1] = pow(v[v.size()-1],2);
                break;
            case 'T': 
                v[v.size()-1] = pow(v[v.size()-1],3);
                break;
            case '*': 
                v[v.size()-1] *= 2;
                v[v.size()-2] *= 2;
                break;
            case '#': 
                v[v.size()-1] *= -1;
                break;
        }
    }
    
    for(auto &e: v) {
        answer += e;
    }
    
    return answer;
}