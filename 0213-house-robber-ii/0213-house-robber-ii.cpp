class Solution {
public:
    int n;
    int solve(int i,vector<int>& nums,int prev,int isFirstTaken,vector<vector<vector<int>>>& dp) {
        if(i>=n) {
            return 0;
        }
        if(i == n-1 && isFirstTaken) {
            return 0;
        }
        if(dp[i][prev+1][isFirstTaken] != -1) {
            return dp[i][prev+1][isFirstTaken];
        }
        int nottake = solve(i+1,nums, prev,isFirstTaken,dp);
        int take = 0;
        if(prev == -1 || prev < i - 1) {
            if(i == 0) {
                isFirstTaken = 1;
            }
            take = nums[i] + solve(i+1,nums,i,isFirstTaken,dp);
        }
        return dp[i][prev+1][isFirstTaken] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(0,nums,-1,0,dp);
    }
};