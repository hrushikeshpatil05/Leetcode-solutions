class Solution {
public:
    int m, n;
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size(), n = text2.size();
        memset(dp, 0, sizeof(dp));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int nottakeFirst = dp[i + 1][ j];
                int nottakeSecond = dp[i][j + 1];
                int take = 0;
                if (text1[i] == text2[j]) {
                    take = 1 + dp[i + 1][j + 1];
                }
                dp[i][j] = max({nottakeFirst, nottakeSecond, take});
            }
        }
        return dp[0][0];
    }
};