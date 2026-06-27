class Solution {
public:
    int findTotalSubArrays(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int ans = 0;

        int left = 0, right = 0;
        int sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findTotalSubArrays(nums,goal) - findTotalSubArrays(nums,goal-1);
    }
};