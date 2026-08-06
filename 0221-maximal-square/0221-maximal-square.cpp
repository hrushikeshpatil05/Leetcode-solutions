class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>currRow(n,0);
        vector<int>nextRow(n,0);


        int maxArea = matrix[m-1][n-1] == '1' ? 1 : 0;

        for(int i=0;i<n;i++) {
            if(matrix[m-1][i] == '1') {
                nextRow[i] = 1;
                maxArea = 1;
            }
        }

        for(int i=m-2;i>=0;i--) {
            currRow[n-1] = matrix[i][n-1] == '1' ? 1 : 0;
            maxArea = max(maxArea,currRow[n-1]);
            for(int j=n-2;j>=0;j--) {
                int right = currRow[j+1];
                int down = nextRow[j];
                int diag = nextRow[j+1];

                if(matrix[i][j] == '1') {
                    currRow[j] = 1 + min({right,down,diag});
                    maxArea = max(maxArea,currRow[j]);
                }
                else {
                    currRow[j] = 0;
                }
            }
            nextRow = currRow;
        }
        return maxArea*maxArea;
    }
};