class Solution {
public:
    int dp[201][201];
    int solve(int i,int j) {
        if(i>=j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int minCost = 1e8;
        for(int k=i;k<=j;k++) {
            int goRight = solve(i,k-1);
            int goLeft = solve(k+1,j);

            minCost = min(minCost,k + max(goRight,goLeft));
        }
        return dp[i][j] = minCost;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
       return solve(1,n);
    }
};