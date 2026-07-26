class Solution {
public:
    int n;
    bool solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (target < 0 || i >= n) {
            return false;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        bool nottake = solve(i + 1, nums, target, dp);
        bool take = solve(i + 1, nums, target - nums[i], dp);

        return dp[i][target] = (take || nottake);
    }
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
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(0, nums, target, dp);
    }
};