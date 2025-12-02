class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_cnt[26];
        int t_cnt[26];
        int i = 0;
        for( i=0;i<s.size();i++){
            s_cnt[s[i]-'a']++;
            t_cnt[t[i]-'a']++;
        }
        t_cnt[t[i]-'a']++;

        for(i=0;i<26;i++){
            if(s_cnt[i] != t_cnt[i])return 'a' + i;
        }

        return NULL;
    }

};