class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxSum = INT_MIN;

        for(int i=0;i<m;i++) {
            vector<int>rowSum(n,0);

            for(int j=i;j<m;j++) {

                for(int row=0;row<n;row++) {
                    rowSum[row] += matrix[row][j];
                }

                set<int>prefSum;

                prefSum.insert(0);
                int currSum = 0;

                for(int row = 0; row < n; row++) {
                    currSum += rowSum[row];

                    auto it = prefSum.lower_bound(currSum-k);

                    if(it != prefSum.end()) {
                        maxSum = max(maxSum,currSum - *it);
                    }
                    prefSum.insert(currSum);
                }
            }
        }
        return maxSum;
    }
};