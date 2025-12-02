class Solution {
private:
    int dp[10001] = { 0, };
public:
    Solution(){
        memset(dp, -1, sizeof dp);
        for(int i = 1 ; i*i <= 10000; i++){
            dp[i*i] = 1;
        }
    }
    int numSquares(int n) {
        int &ret = dp[n];
        if(ret != -1) return ret;

        int minVal = INT32_MAX;
        for(int i=1; i *i < n; i++){
            int res = numSquares(n-i*i);
            minVal = min(minVal, res);
        }

        return ret = minVal + 1;
    }
};