class Solution {
    int[] dp = new int[400];
    int[] input;

    private int solve(int n) {
        if (dp[n] != -1 || n < 2) return dp[n];
        int currentSum = solve(n - 2) + input[n]; // n + (n-2)
        int prevSum = solve(n - 1);
        int result = Math.max(currentSum, prevSum);
        return dp[n] = result;
    }

    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        if (nums.length == 2) return Math.max(nums[0], nums[1]);
        input = nums;
        Arrays.fill(dp, -1);
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        return solve(nums.length - 1);

    }
}