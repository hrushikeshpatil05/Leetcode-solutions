class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<int>nextRow(n,0);

        for(int i=0;i<n;i++) {
            nextRow[i] = triangle[m-1][i];
        }

        for(int i=m-2;i>=0;i--) {
            for(int j=0;j<triangle[i].size();j++) {
                nextRow[j] = triangle[i][j] + min(nextRow[j+1],nextRow[j]);
            }
        }
        return nextRow[0];
    }
};