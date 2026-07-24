class Solution {
public:
    int n = 0;
    int solve(int i, vector<int>& nums, int prevIdx, vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }

        if (dp[i][prevIdx + 1] != -1) {
            return dp[i][prevIdx + 1];
        }

        int nottake = solve(i + 1, nums, prevIdx, dp);
        int take = 0;
        if (prevIdx == -1 || nums[i] > nums[prevIdx]) {
            take = 1 + solve(i + 1, nums, i, dp);
        }
        return dp[i][prevIdx + 1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int nottake = dp[i + 1][j + 1];
                int take = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][j + 1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
};