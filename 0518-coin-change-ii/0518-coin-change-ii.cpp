class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<long long>dp(amount+1,0);
        int limit = INT_MAX;
        dp[0] = 1;

        for(int i=0;i<n;i++) {
            for(int j=coins[i];j<=amount;j++) {
                dp[j] = dp[j] + dp[j-coins[i]];
                if(dp[j] >= limit) {
                    dp[j] = limit;
                }
            }
        }
        return dp[amount];
    }
};