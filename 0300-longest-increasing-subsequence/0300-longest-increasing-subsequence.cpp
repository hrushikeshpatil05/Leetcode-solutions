class Solution {
public:
    int n = 0;
    int solve(int i, vector<int>& nums, int prevIdx,vector<vector<int>>& dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i][prevIdx+1] != -1) {
            return dp[i][prevIdx+1];
        }

        int nottake = solve(i+1,nums,prevIdx,dp);
        int take = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx]) {
            take = 1 + solve(i+1,nums,i,dp);
        }
        return dp[i][prevIdx+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};