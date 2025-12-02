class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int upper = 0;
        digits[digits.size() - 1] += 1;
        if(digits[digits.size() - 1] > 9){
            upper = 1;
            digits[digits.size() - 1] %= 10;
        }
        for(int i=digits.size()-2; i>=0;i--){
            if(upper == 0) break;
            digits[i] += upper;

            upper = digits[i] / 10;
            if(digits[i] > 9){
                digits[i] %= 10;
            }
        }
        if(upper == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};