class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totalSum = accumulate(stones.begin(),stones.end(),0);

        int targetSum = totalSum/2;

        int ans = targetSum;

        vector<bool>dp(targetSum+1,false);
        dp[0] = true;

        for(auto num : stones) {
            for(int j=targetSum;j>=num;j--) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        
        for(int i=targetSum;i>=0;i--) {
            if(dp[i] == true) {
                return totalSum - (2*i);
            }
        }
        return 0;
    }
};