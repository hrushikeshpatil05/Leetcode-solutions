class Solution {
public:
    int n;
    int dp[5001][2];
    int solve(int i,bool hasTaken, vector<int>& prices) {
        if(i>=n) {
            return 0;
        }

        if(dp[i][hasTaken] != -1) {
            return dp[i][hasTaken];
        }

        int nottake = solve(i+1,hasTaken,prices);
        int take = 0;
        if(!hasTaken) {
            take = -prices[i] + solve(i+1,true,prices);
        }
        else {
            take = prices[i] + solve(i+2,false,prices);
        }
        return dp[i][hasTaken] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,false,prices);
    }
};