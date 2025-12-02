#include <bits/stdc++.h>

using namespace std;

/*
- sizes를 순회하면서 w, h 를 포함할 수 있는 것을 순차적으로 구해나간다.
- w,h를 포함하기 위해서 **돌리기 연산**을 할 수있다. 
  - 만약 포함되지 않는다면 w,h를 포함할 수 있는 가장 작은 크기로 반영한다.
*/
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> cur= {0, 0};
    
    for(int i=0;i<sizes.size();i++){
        sort(sizes[i].begin(), sizes[i].end());
        
        if(cur[0] < sizes[i][0]) cur[0] = sizes[i][0];
        if(cur[1] < sizes[i][1]) cur[1] = sizes[i][1];
    }
    
    int ret = cur[0] * cur[1];
    return ret;
}