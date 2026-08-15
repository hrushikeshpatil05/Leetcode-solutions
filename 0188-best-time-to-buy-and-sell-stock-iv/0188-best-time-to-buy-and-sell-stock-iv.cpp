class Solution {
public:
    int n;
    int dp[1001][2][101];
    int solve(int i, bool hasTaken, vector<int>& prices,int k) {
        if(k == 0 || i >= n) {
            return 0;
        }

        if(dp[i][hasTaken][k] != -1) {
            return dp[i][hasTaken][k];
        }

        int nottake = solve(i+1,hasTaken,prices,k);
        int take = 0;

        if(!hasTaken) {
            take = -prices[i] + solve(i+1,true,prices,k);
        }
        else {
            take = prices[i] + solve(i+1,false,prices,k-1);
        }
        return dp[i][hasTaken][k] = max(take,nottake);
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,false,prices,k);
    }
};