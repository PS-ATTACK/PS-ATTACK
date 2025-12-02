class Solution {
    vector<int> dp;
public:
    // 이전 dp[n-1] + dp[n], dp[n] 
    int maxSubArray(vector<int>& nums) {
        dp = vector<int>(1e5 + 1) ;
        fill(dp.begin(), dp.end(), INT32_MIN);
        // memset(dp, -1, sizeof dp);
        dp[0] = nums[0];
        for(int i =1; i<nums.size();i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};