class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int minSum = 1e8;

        vector<int>nextRow(n,0);
        
        vector<int>currRow(n,1e8);

        for(int i=0;i<n;i++) {
            nextRow[i] = matrix[m-1][i];
        }

        for(int i=m-2;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                int down = nextRow[j];
                if(j>0) {
                    down = min(nextRow[j-1],down);
                }
                if(j<n-1) {
                    down = min(nextRow[j+1],down);
                }
                currRow[j] = matrix[i][j] + min(currRow[j],down);
            }
            nextRow = currRow;
        }
        for(int i=0;i<n;i++) {
            minSum = min(minSum,nextRow[i]);
        }
        return minSum;
    }
};