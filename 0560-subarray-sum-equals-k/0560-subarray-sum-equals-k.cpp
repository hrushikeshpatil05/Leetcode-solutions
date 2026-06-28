class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>count;

        count[0] = 1;
        int currSum = 0;
        int subArraysCount = 0;
        for(int i=0;i<n;i++) {
            currSum += nums[i];
            int requiredSum = currSum - k;

            if(count.find(requiredSum) != count.end()) {
                subArraysCount += count[requiredSum];
            }

            count[currSum]++;
        }

        return subArraysCount;
    }
};