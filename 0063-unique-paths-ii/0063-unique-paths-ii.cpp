class Solution {
public:
    int m,n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        // vector<vector<long long>>dp(m,vector<long long>(n,0));
        vector<long long>nextRow(n,0);
        vector<long long>currRow(n,0);

        if(m>=2 && n >= 1&& obstacleGrid[m-2][n-1] == 0) {
            currRow[n-1] = 1;
        }

        for(int j=n-1;j>=0;j--) {
            if(obstacleGrid[m-1][j] == 1) {
                break;
            }
            nextRow[j] = 1;
        }

        for(int i=m-2;i>=0;i--) {
            currRow[n-1] = obstacleGrid[i][n-1] == 1 ? 0 : nextRow[n-1];
            for(int j=n-2;j>=0;j--) {
                if(obstacleGrid[i][j] == 1) {
                    currRow[j] = 0;
                }
                else {
                    currRow[j] = nextRow[j] + currRow[j+1];
                }
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
};