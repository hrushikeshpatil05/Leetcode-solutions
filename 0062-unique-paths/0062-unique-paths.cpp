class Solution {
public:
    // int solve(int i,int j,int m,int n) {
    //     if(i == m-1 && j == n-1) {
    //         return 1;
    //     }
    //     if(i>=m || j>=n) {
    //         return 0;
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int down = solve(i+1,j,m,n);
    //     int right = solve(i,j+1,m,n);
    //     return dp[i][j] = down + right;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            dp[i][n-1] = 1;
        }
        for(int j=0;j<n;j++) {
            dp[m-1][j] = 1;
        }

        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
        // return solve(0,0,m,n);
    }
};