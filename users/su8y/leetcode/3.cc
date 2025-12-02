class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int len = s.size();
        if(s.size() == 1) return 1;

        int ret = 0;
        for(int i=0;i<len;i++){
            set<char> nameSet;
            for(int j=i;j<len;j++){
                /* not conatins */
                bool isNotConatins = nameSet.find(s[j]) == nameSet.end();
                if(isNotConatins){
                    nameSet.insert(s[j]);
                }else{
                    break;
                }
            }
            ret = max(ret, (int) nameSet.size());
        }
        
        return ret;
    }
};