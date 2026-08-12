class Solution {
public:
    int dp[201][201];
    int getMoneyAmount(int n) {
        memset(dp,0,sizeof(dp));

        for(int i=n;i>=1;i--) {
            for(int j=i;j<=n;j++) {
                dp[i][j] = INT_MAX;
                if(i == j) {
                    dp[i][j] = 0;
                }
                for(int k=i;k<=j;k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k-1],dp[k+1][j]));
                }
            }
        }
       return dp[1][n];
    }
};