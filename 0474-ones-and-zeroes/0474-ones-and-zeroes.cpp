class Solution {
public:
    int size;
    int dp[601][101][101];
    int solve(int i,vector<vector<int>>& nums,int m,int n) {
        if(i>=size) {
            return 0;
        }

        if(dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        int nottake = solve(i+1,nums,m,n);
        int take = 0;
        if(nums[i][0] <= m && nums[i][1] <= n) {
            take = 1 + solve(i+1,nums,m-nums[i][0],n-nums[i][1]);
        }
        return dp[i][m][n] = max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        size = strs.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>nums;
        for(int i=0;i<size;i++) {
            int ct0 = 0,ct1 = 0;
            for(int j=0;j<strs[i].size();j++) {
                if(strs[i][j] == '0') ct0++;
                else ct1++;
            }
            nums.push_back({ct0,ct1});
        }
        return solve(0,nums,m,n);
    }
};