class Solution {
    private static int[] dp = new int[38];
    private static int solve(int n) {
        if (dp[n] != -1 || n < 3) return dp[n];
        int sum = 0;
        for (int i = 1; i <= 3; i++) {
            sum += solve(n - i);
        }
        dp[n] = sum;
        return sum;
    }
    public int tribonacci(int n) {
        // initialize dp table 
        Arrays.fill(dp, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        return solve(n);
    }
}