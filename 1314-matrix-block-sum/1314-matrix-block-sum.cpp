class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>prefSum(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                prefSum[i+1][j+1] = prefSum[i+1][j] + prefSum[i][j+1] + mat[i][j] - prefSum[i][j];
            }
        }

        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int r1 = max(0,i-k) + 1;
                int c1 = max(0,j-k) + 1;
                int r2 = min(n-1,i+k) + 1;
                int c2 = min(m-1,j+k) + 1;

                ans[i][j] = prefSum[r2][c2] - prefSum[r1-1][c2] - prefSum[r2][c1-1] + prefSum[r1-1][c1-1];
            }
        }
        return ans;
    }
};