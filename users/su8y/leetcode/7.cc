class Solution {
public:
    int reverse(int x) {
        bool minus = x < 0;
        string s = to_string(x);
        string ret; 
        bool firstZeroFlag = true;
        for(int i=s.size()-1; i>=0; i--){
            if(firstZeroFlag && s[i] == '0'){
                continue;
            }
            firstZeroFlag = false;
            ret += s[i];
        }
        if(firstZeroFlag) return 0;
        
        long int intRet = minus ? -stol(ret) : stol(ret);
        if(intRet <= INT32_MIN || intRet >= INT32_MAX) return 0;
        return (int) intRet;
    }
};