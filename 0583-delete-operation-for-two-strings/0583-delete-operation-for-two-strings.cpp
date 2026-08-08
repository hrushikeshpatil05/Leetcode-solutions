class Solution {
public:
    int m, n;
    // int dp[501][501];
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        // memset(dp, 0, sizeof(dp));

        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);

        // for(int i=0;i<=m;i++) {
        //     dp[i][n] = m-i;
        // }

        for(int j=0;j<=n;j++) {
            next[j] = n-j;
        }

        for (int i = m - 1; i >= 0; i--) {
            curr[n] = m - i;
            for (int j = n - 1; j >= 0; j--) {
                int take = 1e8;
                if (word1[i] == word2[j]) {
                    take = next[j + 1];
                }
                int deleteChar1 = 1 + next[j];
                int deleteChar2 = 1 + curr[j + 1];

                curr[j] = min({take, deleteChar1, deleteChar2});
            }
            next = curr;
        }
        return next[0];
    }
};