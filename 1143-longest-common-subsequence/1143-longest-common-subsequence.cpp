class Solution {
public:
    int m, n;
    // int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size(), n = text2.size();
        vector<int> curr(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            int prevDiag = 0;
            for (int j = n - 1; j >= 0; j--) {
                int temp = curr[j];
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + prevDiag;
                } else {
                    curr[j] = max(curr[j + 1], curr[j]);
                }
                prevDiag = temp;
            }
        }
        return curr[0];
    }
};