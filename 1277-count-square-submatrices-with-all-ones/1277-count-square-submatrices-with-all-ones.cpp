class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> nextRow(n, 0);
        vector<int> currRow(n, 0);

        // vector<int> squares(301, 0);
        int noOfSquares = 0;

        for (int i = 0; i < n; i++) {
            nextRow[i] = matrix[m - 1][i];
            if (nextRow[i]) {
                noOfSquares++;
            }
            // squares[nextRow[i]]++;
        }

        for (int i = m - 2; i >= 0; i--) {
            currRow[n - 1] = matrix[i][n - 1];
            if (currRow[n - 1]) {
                noOfSquares++;
            }
            for (int j = n - 2; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                    int size =
                        min({nextRow[j], nextRow[j + 1], currRow[j + 1]});
                    currRow[j] = 1 + size;
                    noOfSquares += currRow[j];
                } else {
                    currRow[j] = 0;
                }
            }
            nextRow = currRow;
        }

        return noOfSquares;
    }
};