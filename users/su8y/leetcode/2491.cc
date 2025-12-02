class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size() - 1;
        int checkVal = -1;
        long long ret = 0;
        while(l < r){
            int sumVal = nums[l] + nums[r];
            if(checkVal == -1) checkVal = sumVal;
            else {
                if(sumVal != checkVal) {
                    return -1;
                }
            }
            ret += nums[l] * nums[r];
            l++; r--;
        }
        return ret;
    }
};