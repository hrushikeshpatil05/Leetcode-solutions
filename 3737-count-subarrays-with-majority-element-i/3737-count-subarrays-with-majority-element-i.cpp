class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefCount(n + 1, 0);
        prefCount[0] = nums[0] == target ? 1 : 0;
        for (int i = 0; i < n; i++) {
            prefCount[i + 1] = prefCount[i] + (nums[i] == target ? 1 : 0);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int currCount = prefCount[j+1] - prefCount[i];
                int size = (j - i + 1) / 2;
                if (currCount > size) {
                    ans++;
                }
            }
        }
        return ans;
    }
};