class Solution {
public:
    int n;
    int dp[41][41];
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        memset(dp, 0, sizeof(dp));

        vector<vector<int>> maxi(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            maxi[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[i][j] = max(maxi[i][j - 1], arr[j]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (i == j) {
                    dp[i][j] = 0;
                    continue; 
                }

                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int currentRootCost = maxi[i][k] * maxi[k + 1][j];
                    int leftTreeCost = dp[i][k];
                    int rightTreeCost = dp[k + 1][j];

                    int curSum = currentRootCost + leftTreeCost + rightTreeCost;
                    
                    dp[i][j] = min(dp[i][j], curSum);
                }
            }
        }
        return dp[0][n - 1];
    }
};