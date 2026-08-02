class Solution {
public:
    int n;
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum < abs(target) || (target + sum)%2 != 0) {
            return 0;
        }

        int newT = (sum + target)/2;

        vector<int>dp(newT+1,0);
        dp[0] = 1;
        // return solve(0,0,nums,target,dp);
        int ans = 0;
        for(auto num : nums) {
            for(int j=newT;j>=num;j--) {
                dp[j] = dp[j] + dp[j-num];
            }
        }
        return dp[newT];
    }
};