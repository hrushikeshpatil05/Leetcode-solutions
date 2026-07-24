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
        vector<int>dp(n+1,-1);
        return solve(0,n,dp);
    }
};