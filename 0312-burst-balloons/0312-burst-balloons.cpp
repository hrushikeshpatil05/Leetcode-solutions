class Solution {
public:
    int n;
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        vector<int>temp = {1};

        for(int i=0;i<n;i++) {
            temp.push_back(nums[i]);
        }
        temp.push_back(1);

        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int left=n;left>=1;left--) {
            for(int right=left;right<=n;right++) {
                for(int k=left;k<=right;k++) {
                    int currSum = temp[left-1]*temp[k]*temp[right+1];

                    int remSum = dp[left][k-1] + dp[k+1][right];

                    dp[left][right] = max(dp[left][right],currSum + remSum);
                }
            }
        }

        return dp[1][n];
    }
};