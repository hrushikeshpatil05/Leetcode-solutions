class Solution {
public:
    int n;
    int dp[50][50];
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        memset(dp,0,sizeof(dp));

        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                for(int k=i+1;k<j;k++) {
                    int temp = values[i]*values[j]*values[k] + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j],temp);
                } 
            }
        }
        return dp[0][n-1];
    }
};