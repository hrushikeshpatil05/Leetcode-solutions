class Solution {
public:
    int n;
    int solve(int i,int prev,vector<vector<int>>& pairs,vector<vector<int>>& dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i][prev+1] != -1) {
            return dp[i][prev+1];
        }

        int nottake = solve(i+1,prev,pairs,dp);
        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1]) {
            take = 1 + solve(i+1,i,pairs,dp);
        }

        return dp[i][prev+1] = max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        n = pairs.size();

        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(0,-1,pairs,dp);
    }
};