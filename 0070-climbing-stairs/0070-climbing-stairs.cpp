class Solution {
public:
    int solve(int step, int n,vector<int>& dp) {
        if(step > n) {
            return 0;
        }
        if(step == n) {
            return 1;
        }
        if(dp[step] != -1) {
            return dp[step];
        }
        int takeOneStep = solve(step+1,n,dp);
        int takeTwoSteps = solve(step+2,n,dp);
        return dp[step] = takeOneStep + takeTwoSteps;
    }
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        vector<int>dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        // return solve(0,n,dp);
    }
};