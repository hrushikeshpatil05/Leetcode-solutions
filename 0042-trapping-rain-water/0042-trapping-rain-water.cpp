class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        vector<int>leftMax(n,0),rightMax(n,0);
        int currMax = nums[0];
        for(int i=0;i<n;i++) {
            currMax = max(currMax,nums[i]);
            leftMax[i] = currMax;
        }

        currMax = nums[n-1];
        for(int i=n-1;i>=0;i--) {
            currMax = max(currMax,nums[i]);
            rightMax[i] = currMax;
        }

        int ans = 0;

        for(int i=0;i<n;i++) {
            ans += (min(leftMax[i],rightMax[i]) - nums[i]);
        }

        return ans;
    }
};