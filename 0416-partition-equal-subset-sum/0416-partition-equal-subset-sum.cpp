class Solution {
public:
    int n;
    // bool solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
    //     if (target == 0) {
    //         return true;
    //     }
    //     if (target < 0 || i >= n) {
    //         return false;
    //     }

    //     if (dp[i][target] != -1) {
    //         return dp[i][target];
    //     }

    //     bool nottake = solve(i + 1, nums, target, dp);
    //     bool take = solve(i + 1, nums, target - nums[i], dp);

    //     return dp[i][target] = (take || nottake);
    // }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i=0;i<=n;i++) {
            dp[i][0] = true;
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=target;j>=0;j--) {
                bool nottake = dp[i + 1][j];
                bool take = false;
                if(j-nums[i] >= 0) {
                    take = dp[i + 1][j - nums[i]];
                }
                dp[i][j] = (take || nottake);
            }
        }
        return dp[0][target];
    }
};