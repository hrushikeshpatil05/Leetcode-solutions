class Solution {
public:
    int m,n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        vector<vector<long long>>dp(m,vector<long long>(n,0));

        for(int i=m-1;i>=0;i--) {
            if(obstacleGrid[i][n-1] == 1) {
                break;
            }
            dp[i][n-1] = 1;
        }

        for(int j=n-1;j>=0;j--) {
            if(obstacleGrid[m-1][j] == 1) {
                break;
            }
            dp[m-1][j] = 1;
            // cout<<dp[m-1][j]<<endl;
        }

        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};