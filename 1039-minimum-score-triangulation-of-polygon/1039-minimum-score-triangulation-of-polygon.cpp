class Solution {
public:
    int n;
    int dp[50][50];
    int solve(int i,int j,vector<int>& values) {
        if(i>=j || j-i<2) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 1e8;
        for(int k=i+1;k<j;k++) {
            int temp = values[i]*values[j]*values[k] + solve(i,k,values) + solve(k,j,values);
            take = min(take,temp);
        }
        return dp[i][j] = take;
    }
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,values);
    }
};