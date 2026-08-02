class Solution {
public:
    int n;

    void generateCombinations(int i,int j,int count, int currSum,vector<int>& nums, vector<vector<int>>& subGroups) {
        if(i == j) {
            subGroups[count].push_back(currSum);
            return;
        }
        generateCombinations(i+1,j,count,currSum,nums,subGroups);
        generateCombinations(i+1,j,count+1,currSum+nums[i],nums,subGroups);
    }
    // long long totalSum;
    // long long solve(int i,long long sum,vector<int>& nums,int size,map<tuple<int, long long, int>,long long>& dp) {
    //     if(i>=n) {
    //         return 1e8;
    //     }

    //     if(size == n/2) {
    //         long long nextSum = (totalSum - sum);
    //         return abs(nextSum-sum);
    //     }

    //     if(dp.find({i,sum,size}) != dp.end()) {
    //         return dp[{i,sum,size}];
    //     }

    //     long long nottake = solve(i+1,sum,nums,size,dp);
    //     long long take = 1e8;
    //     if(size < n/2) {
    //         take = solve(i+1,sum+nums[i],nums,size+1,dp);
    //     }
    //     return dp[{i,sum,size}] = min(take,nottake);
    // }
    int minimumDifference(vector<int>& nums) {
        n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        // map<tuple<int, long long, int>,long long> dp;
        // return solve(0,0,nums,0,dp);

        int target = totalSum/2;
        vector<vector<int>>leftSum(n/2+1);
        vector<vector<int>>rightSum(n/2+1);

        generateCombinations(0,n/2,0,0,nums,leftSum);
        
        generateCombinations(n/2,n,0,0,nums,rightSum);

        for(int i=0;i<n/2;i++) {
            sort(rightSum[i].begin(),rightSum[i].end());
        }

        int minDiff = 2e8;

        for(int leftCount = 0;leftCount<n/2;leftCount++) {
            int rightCount = n/2 - leftCount;

            for(auto a:leftSum[leftCount]) {
                int idealB = target - a;

                auto it = lower_bound(rightSum[rightCount].begin(), rightSum[rightCount].end(), idealB);

                if (it != rightSum[rightCount].end()) {
                    int b = *it;
                    int currentSubsetSum = a + b;
                    int diff = abs(totalSum - 2 * currentSubsetSum);
                    minDiff = min(minDiff, diff);
                }

                if (it != rightSum[rightCount].begin()) {
                    auto prevIt = it - 1;
                    int b = *prevIt;
                    int currentSubsetSum = a + b;
                    int diff = abs(totalSum - 2 * currentSubsetSum);
                    minDiff = min(minDiff, diff);
                }
            }
        }
        return minDiff;
    }
};