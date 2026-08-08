class Solution {
public:
    int m, n;
    // int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size(), n = text2.size();
        // memset(dp, 0, sizeof(dp));
        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int nottakeFirst = curr[j+1];
                int nottakeSecond = next[j];
                int take = 0;
                if (text1[i] == text2[j]) {
                    take = 1 + next[j + 1];
                }
                curr[j] = max({nottakeFirst, nottakeSecond, take});
            }
            next = curr;
        }
        return curr[0];
    }
};