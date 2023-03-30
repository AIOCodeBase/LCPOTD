class Solution {
    public boolean isScramble(String s1, String s2) {
        int len = s1.length();
        boolean[][][] dp = new boolean[len + 1][len][len];

        for (int k = 1; k <= len; k++) {
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (k == 1) {
                        dp[k][i][j] = s1.charAt(i) == s2.charAt(j);
                    } else if (i + k <= len && j + k <= len) {
                        for (int q = 1; q < k  && !dp[k][i][j]; q++) {
                            dp[k][i][j] = (dp[q][i][j] && dp[k - q][i + q][j + q]) ||
                                    (dp[q][i][j + k - q] && dp[k - q][i + q][j]);
                            if (dp[k][i][j]) {
                                break;
                            }
                        }
                    }
                }
            }
        }

        return dp[len][0][0];
    }
}