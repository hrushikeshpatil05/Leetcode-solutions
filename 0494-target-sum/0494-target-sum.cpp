class Solution {
public:
    int n;
    int solve(int i,int sum,vector<int>& nums,int target,vector<vector<int>>& dp) {
        if(i==n && sum==target) {
            return 1;
        }
        if(i>=n) {
            return 0;
        }
        if(dp[i][sum + 1000] != -1) {
            return dp[i][sum + 1000];
        }
        int plus = solve(i+1,sum+nums[i],nums,target,dp);
        int minus = solve(i+1,sum-nums[i],nums,target,dp);
        return dp[i][sum + 1000] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2002,-1));
        return solve(0,0,nums,target,dp);
    }
};