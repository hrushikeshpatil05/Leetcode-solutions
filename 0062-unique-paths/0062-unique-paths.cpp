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
        vector<int>nextRow(n,1);
        vector<int>currRow(n,0);
        currRow[n-1] = 1;

        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                currRow[j] = nextRow[j] + currRow[j+1];
            }
            nextRow = currRow;
        }
        return nextRow[0];
        // return solve(0,0,m,n);
    }
};