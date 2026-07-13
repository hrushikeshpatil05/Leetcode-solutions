class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minEl = 0;

        int left = 0, right = n - 1;

        while(left < right){
            int mid = left + (right - left)/2;

            if(nums[right] < nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};