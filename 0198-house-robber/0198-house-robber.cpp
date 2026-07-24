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
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return nums[0];
        }
        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[1],dp[0]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
        }

        return dp[n-1];

        // return solve(0,nums,dp);
    }
};