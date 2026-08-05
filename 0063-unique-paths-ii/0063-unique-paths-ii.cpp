class Solution {
public:
    int m,n;
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if(i>=m || j>=n || grid[i][j] == 1) {
            return 0;
        }
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = solve(i+1,j,grid,dp);
        int right = solve(i,j+1,grid,dp);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(0,0,obstacleGrid,dp);
    }
};