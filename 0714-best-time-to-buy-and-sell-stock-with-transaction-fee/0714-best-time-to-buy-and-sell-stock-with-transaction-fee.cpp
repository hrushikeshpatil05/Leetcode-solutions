class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(int i,bool hasTaken,vector<int>& prices,int fee) {
        if(i>=n) {
            return 0;
        }
        if(dp[i][hasTaken] != -1) {
            return dp[i][hasTaken];
        }
        int nottake = solve(i+1,hasTaken,prices,fee);
        int take = 0;

        if(!hasTaken) {
            take = -prices[i] + -fee + solve(i+1,true,prices,fee);
        }
        else {
            take = prices[i] + solve(i+1,false,prices,fee);
        }

        return dp[i][hasTaken] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        // memset(dp,0,sizeof(dp));
        // return solve(0,false,prices,fee);

        int nextNotHolding = 0;
        int nextHolding = 0;

        for(int i=n-1;i>=0;i--) {
            int currHolding = max(nextHolding,prices[i] - fee + nextNotHolding);

            int currNotHolding = max(nextNotHolding,-prices[i] + nextHolding);

            nextHolding = currHolding;
            nextNotHolding = currNotHolding;
        }
        return nextNotHolding;
    }
};