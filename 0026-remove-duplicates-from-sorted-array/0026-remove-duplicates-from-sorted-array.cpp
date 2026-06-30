class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = 1;

        while(right<n) {
            if(nums[left] != nums[right]) {
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left+1;
    }
};