class Solution {
public:
    int n;
    int dp[100001][2][3];
    int solve(int i, bool hasTaken, vector<int>& prices, int ct) {
        if (ct == 0 || i >= n) {
            return 0;
        }

        if(dp[i][hasTaken][ct] != -1) {
            return dp[i][hasTaken][ct];
        }

        int nottake = solve(i + 1, hasTaken, prices, ct);
        int take = 0;
        if (!hasTaken) {
            take = -prices[i] + solve(i + 1, true, prices, ct);
        } else {
            take = prices[i] + solve(i + 1, false, prices, ct-1);
        }
        return dp[i][hasTaken][ct] = max(take, nottake);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, false, prices, 2);
    }
};