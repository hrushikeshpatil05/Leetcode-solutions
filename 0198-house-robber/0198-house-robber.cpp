class Solution {
public:
    int n;
    int solve(int i, vector<int>& nums,vector<int>& dp) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int nottake = solve(i+1,nums,dp);
        int take = nums[i] + solve(i+2,nums,dp);
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};