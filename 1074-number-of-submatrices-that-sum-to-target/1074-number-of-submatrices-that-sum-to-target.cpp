class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for(int col = 0; col < m; col++) {

            vector<int>rowsSum(n,0);

            for(int j = col; j < m; j++) {

                for(int i = 0; i < n; i++) {
                    rowsSum[i] += matrix[i][j];
                }

                unordered_map<int,int>count;
                count[0] = 1;

                int currSum = 0;

                for(int right = 0; right < n; right++) {
                    currSum += rowsSum[right];

                    int rem = currSum - target;

                    if(count.find(rem) != count.end()) {
                        ans += count[rem];
                    }

                    count[currSum]++;
                }
            }
        }
        return ans;
    }
};