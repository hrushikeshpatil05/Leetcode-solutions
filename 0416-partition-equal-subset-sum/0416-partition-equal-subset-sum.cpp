class Solution {
public:
    int n;

    bool solve(int i,vector<int>& nums,int sum,vector<vector<int>>& dp) {
        if(sum == 0) {
            return true;
        }

        if(i>=n) {
            return false;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        
        bool nottake = solve(i+1,nums,sum,dp);
        bool take = false;

        if(sum - nums[i] >= 0) {
            take = solve(i+1,nums,sum-nums[i],dp);
        }

        return dp[i][sum] = (nottake | take);
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) {
            return false;
        }

        vector<vector<int>>dp(n+1,vector<int>(1e5+1,-1));

        return solve(0,nums,sum/2,dp);
    }
};