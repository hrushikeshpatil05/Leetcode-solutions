class Solution {
public:
    int n;

    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) {
            return false;
        }

        vector<bool>dp(sum/2+1,false);
        dp[0] = true;

        for(int i=0;i<n;i++) {
            for(int j=sum/2;j>=nums[i];j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
                if(dp[sum/2] == true) {
                    return true;
                }
            }
        }
        return false;
    }
};