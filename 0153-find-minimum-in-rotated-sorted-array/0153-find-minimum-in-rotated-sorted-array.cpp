class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minEl = 1e8;

        int left = 0, right = n - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            minEl = min(minEl,nums[mid]);

            if(nums[left] <= nums[mid]) {
                minEl = min(minEl,nums[left]);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return minEl;
    }
};