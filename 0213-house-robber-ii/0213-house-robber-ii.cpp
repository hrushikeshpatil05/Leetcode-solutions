class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0],nums[1]);
        }

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i=1;i<n-1;i++) {
            int curr = nums[i] + prev2;
            prev2 = prev1;
            prev1 = max(prev2,curr);
        }

        int prev3 = nums[1];
        int prev4 = 0;

        for(int i=2;i<n;i++) {
            int curr = nums[i] + prev4;
            prev4 = prev3;
            prev3 = max(prev4,curr);
        }
        return max(prev1,prev3);
    }
};