class Solution {
public:
    int n;
    int dp[41][41];
    int solve(int i,int j,vector<int>& arr) {
        if(i>=j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int sum = 1e8;
        for(int k=i;k<j;k++) {
            int leftMaxEl = *max_element(arr.begin()+i,arr.begin()+k+1);
            int rightMaxEl = *max_element(arr.begin()+k+1,arr.begin()+j+1);

            int curSum = leftMaxEl*rightMaxEl + solve(i,k,arr) + solve(k+1,j,arr);

            sum = min(sum,curSum);
        }
        return dp[i][j] = sum;
    }
    int mctFromLeafValues(vector<int>& arr) {
        n = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,arr);
    }
};