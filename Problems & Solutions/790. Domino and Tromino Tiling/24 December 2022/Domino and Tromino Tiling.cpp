class Solution {
private:
    const int mod = 1e9+7;
public:
    int numTilings(int n) {
        int dp[1+n];
        dp[0] = 1;
        for (int i = 1;i <= n;++i) {
            dp[i] = dp[i-1];
            if (i > 1) dp[i] = (dp[i] + dp[i-2]) % mod;
            for (int j = 3;j <= i;j += 2)
                dp[i] = (dp[i] + 2 * dp[i - j] % mod) % mod;
            for (int j = 4;j <= i;j += 2)
                dp[i] = (dp[i] + 2 * dp[i - j] % mod) % mod;
        }
        return dp[n];
    }
};