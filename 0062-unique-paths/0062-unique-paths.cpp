class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));

        vector<int>nextRow(n,0);
        vector<int>currRow(n,0);

        for (int j = 0; j < n; j++) {
            nextRow[j] = 1;
        }

        currRow[n-1] = 1;

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int goDown = nextRow[j];
                int goRight = currRow[j + 1];
                currRow[j] = goDown + goRight;
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};