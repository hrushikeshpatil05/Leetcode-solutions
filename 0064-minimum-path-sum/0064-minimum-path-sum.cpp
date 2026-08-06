class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>nextRow(n,0);
        vector<int>currRow(n,0);

        nextRow[n-1] = grid[m-1][n-1];

        for(int i=n-2;i>=0;i--) {
            nextRow[i] = nextRow[i+1] + grid[m-1][i];
        }

        for(int i=m-2;i>=0;i--) {
            currRow[n-1] = nextRow[n-1] + grid[i][n-1];
            for(int j=n-2;j>=0;j--) {
                int right = currRow[j+1] + grid[i][j];
                int down = nextRow[j] + grid[i][j];

                currRow[j] = min(right,down);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};