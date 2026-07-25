class Solution {
public:
    int m, n;

    int solve(int i, int j, string& text1, string& text2,
              vector<vector<int>>& dp) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 0;
        if (text1[i] == text2[j]) {
            take = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }
        int nottakeFirst = solve(i + 1, j, text1, text2, dp);
        int nottakeSecond = solve(i, j + 1, text1, text2, dp);
        return dp[i][j] = max({nottakeFirst, nottakeSecond, take});
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, text1, text2, dp);
    }
};