class Solution {
public:
    int n;
    int dp[301][301];
    int solve(int i,int j,vector<int>& nums) {
        if(i>j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxSum = 0;
        for(int k=i;k<=j;k++) {
            int curSum = nums[i-1]*nums[k]*nums[j+1];

            int remSum = solve(i,k-1,nums) + solve(k+1,j,nums);
            maxSum = max(maxSum,curSum + remSum);
        }
        return dp[i][j] = maxSum;

    }
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        vector<int>temp = {1};

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++) {
            temp.push_back(nums[i]);
        }
        temp.push_back(1);

        return solve(1,n,temp);
    }
};