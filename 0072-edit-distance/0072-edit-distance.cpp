class Solution {
public:
    int m, n;
    // int solve(int i, int j, string& word1, string& word2,
    //           vector<vector<int>>& dp) {
    //     if (i >= m) {
    //         return n - j;
    //     }
    //     if (j >= n) {
    //         return m - i;
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int take = 1e8;
    //     int nottake = 1e8;
    //     if (word1[i] == word2[j]) {
    //         take = solve(i + 1, j + 1, word1, word2, dp);
    //     } else {
    //         int insertChar = 1 + solve(i, j + 1, word1, word2, dp);
    //         int deleteChar = 1 + solve(i + 1, j, word1, word2, dp);
    //         int replaceChar = 1 + solve(i + 1, j + 1, word1, word2, dp);
    //         nottake = min({insertChar, deleteChar, replaceChar});
    //     }
    //     return dp[i][j] = min(take, nottake);
    // }
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e8));

        vector<int> currRow(n + 1, 1e8), nextRow(n + 1, 1e8);

        for (int j = 0; j <= n; j++) {
            nextRow[j] = n - j;
        }

        for (int i = m - 1; i >= 0; i--) {
            currRow[n] = m - i;
            for (int j = n - 1; j >= 0; j--) {
                int take = 1e8;
                int nottake = 1e8;
                if (word1[i] == word2[j]) {
                    currRow[j] = nextRow[j + 1];
                } else {
                    int insertChar = 1 + currRow[j + 1];
                    int deleteChar = 1 + nextRow[j];
                    int replaceChar = 1 + nextRow[j + 1];
                    currRow[j] = min({insertChar, deleteChar, replaceChar});
                }
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};