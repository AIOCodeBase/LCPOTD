class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[3][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<n+1; i++){
            for (int j= i-1; j>=1; j--){
                dp[2][i] = max(dp[2][i], dp[1][j] + prices[i-1] - prices[j-1]);
            }
            dp[0][i] = max({dp[0][i], dp[2][i-1], dp[1][i-1],dp[0][i-1]});
            dp[1][i] = max(dp[1][i], dp[0][i-1]);
        }
        for (int k=0; k<3; k++){
            for (int i=0; i < n+1; i++){
                printf("%d ", dp[k][i]);
            }
            printf("\n");
        }
        
        return max({dp[0][n],dp[1][n],dp[2][n]});
    }
};