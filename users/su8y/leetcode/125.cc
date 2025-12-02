class Solution {
bool isAlpha(int i, const string & str){
    return (str[i] >= 'a' && str[i] <= 'z' ) || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9');
}
void transLowCase(char *ch){
    for(int i=0;i<2;i++) {
        if(ch[i] >= 'A' && ch[i] <= 'Z') {
            ch[i] = ch[i] + 32;
        }
    }
}
public:
    bool isPalindrome(string s) {
    int l=0, r=s.size()-1;

    while(l < r){
        while(l < s.size() &&!isAlpha(l, s)) l++;
        while(r >= 0 && !isAlpha(r, s)) r--;

        if(l < 0 || l >= s.size() || r < 0 || r >= s.size()) return true;

        
        char ch[2] = {s[l], s[r]};

        transLowCase(ch);
        if(ch[0] != ch[1]) return false;

        l++;
        r--;
    }

    return true;
    }
};