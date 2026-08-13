class Solution {
public:
    int n;
    int solve(int i,vector<int>& prices,bool holding,vector<vector<int>>& dp) {
        if(i>=n) {
            return 0;
        }

        if(dp[i][holding] != -1) {
            return dp[i][holding];
        }

        int nottake = solve(i+1,prices,holding,dp);
        int take = 0;
        if(holding) {
            take = prices[i] + solve(i+1,prices,false,dp);
        }
        else {
            take = -1*prices[i] + solve(i+1,prices,true,dp);
        }

        return dp[i][holding] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,false,dp);
    }
};