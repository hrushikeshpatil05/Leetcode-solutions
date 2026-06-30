class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        int leftMax = nums[0];
        int rightMax = nums[n-1];

        int ans = 0;
        int left = 0, right = n-1;

        while(left < right) {
            leftMax = max(leftMax, nums[left]);
            rightMax = max(rightMax,nums[right]);

            if(leftMax < rightMax) {
                ans += (leftMax - nums[left]);
                left++;
            }
            else {
                ans += (rightMax - nums[right]);
                right--;
            }
        }

        return ans;
    }
};