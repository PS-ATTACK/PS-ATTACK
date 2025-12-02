class Solution {
private:
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 1) return s;
        vector<vector<int>> checkPalin(len + 1,vector<int>(len,0));
        // fill(&checkPalin[0][0], checkPalin[1][0] + len,);
        for(int i=0; i<2; i++)
            fill(checkPalin[i].begin(), checkPalin[i].begin() + len, 1); /* 0, 1 index init one*/

        int maxLen = 0;
        pair<int,int> index;

        for(int i=1; i<len+1; i++){
            for(int j=0; j<len-1; j++){
                if(i == 1 || checkPalin[i-2][j+1] == 1){ // j + 1 부터 시작하는 i-2 크기의 문자열이 Palin이고
                    if(s[j] == s[i + j - 1]){ // j == j + i - 1 i크기의 문자열 양 끝이 똑같다면 
                        checkPalin[i][j] = 1;
                        if(maxLen < i){
                            index = {j,i};
                            maxLen = i;
                        }
                    }
                }

            }
        }
        

        return s.substr(index.first, index.second);
        
    }
};