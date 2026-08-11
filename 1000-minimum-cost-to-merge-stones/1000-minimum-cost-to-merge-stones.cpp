class Solution {
public:
    int n;
    int prefSum[31];
    int dp[31][31];
    int solve(int i, int j, vector<int>& stones, int k) {
        if (i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int minCost = 1e8;
        for (int m = i; m < j; m += (k - 1)) {

            int leftSum = solve(i, m, stones, k);
            int rightSum = solve(m + 1, j, stones, k);

            minCost = min(minCost, leftSum + rightSum);
        }

        int length = j - i + 1;
        if ((length-1) % (k - 1) == 0) {
            minCost += prefSum[j+1] - prefSum[i];
        }
        return dp[i][j] = minCost;
    }
    int mergeStones(vector<int>& stones, int k) {
        n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        memset(dp,-1,sizeof(dp));
        memset(prefSum,0,sizeof(prefSum));
        for (int i = 0; i < n; i++) {
            prefSum[i+1] = stones[i] + prefSum[i];
        }
        return solve(0, n - 1, stones, k);
    }
};