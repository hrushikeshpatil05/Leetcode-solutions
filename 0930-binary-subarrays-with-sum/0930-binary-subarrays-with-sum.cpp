class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        map<int,int>count;

        count[0] = 1;

        int ans = 0;
        int currSum = 0;

        for(int i=0;i<n;i++) {
            currSum += nums[i];

            int requiredSum = currSum - goal;

            if(count.find(requiredSum) != count.end()) {
                ans += count[requiredSum];
            }
            count[currSum]++;
        }
        return ans;
    }
};