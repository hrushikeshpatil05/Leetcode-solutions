class Solution {
public:
    int solve(vector<int>& nums,int k) {
        int n = nums.size();

        int left = 0;
        int ctOfArrays = 0;
        int oddCt = 0;

        for(int right = 0; right < n; right++) {
            if(nums[right]%2 != 0) {
                oddCt++;
            }

            while(oddCt > k) {
                if(nums[left]%2 != 0) {
                    oddCt--;
                }
                left++;
            }

            ctOfArrays += (right - left + 1);
        }
        return ctOfArrays;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);

    }
};