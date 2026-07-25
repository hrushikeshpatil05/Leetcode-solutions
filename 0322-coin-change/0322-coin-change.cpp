class Solution {
public:
    int n;
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (i >= n) {
            return 1e8;
        }
        if (amount == 0) {
            return 0;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int nottake = solve(i + 1, coins, amount, dp);
        int take = 1e8;
        if (amount - coins[i] >= 0) {
            take = 1 + solve(i, coins, amount - coins[i], dp);
        }
        return dp[i][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e8));

        vector<int>prev(amount+1,1e8), curr(amount+1,0);

        prev[0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                int nottake = prev[j];
                int take = 1e8;
                if (j - coins[i] >= 0) {
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take, nottake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        // int ans = solve(0, coins, amount, dp);
        return ans == 1e8 ? -1 : ans;
    }
};