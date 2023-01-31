class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if (n == 1) return true;
        boolean[] dp = new boolean[n];
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j + nums[j] >= i) { dp[i] = dp[j]; continue; }
            }
        }
        return dp[n - 1];
    }
}