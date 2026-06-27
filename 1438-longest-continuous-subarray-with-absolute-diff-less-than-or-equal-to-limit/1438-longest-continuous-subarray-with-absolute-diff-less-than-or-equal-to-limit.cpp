class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int left = 0;

        int ans = 0;

        map<int,int>mp;

        for(int right = 0; right < n; right++) {
            mp[nums[right]]++;

            int currMax = mp.rbegin()->first;
            int currMin = mp.begin()->first;

            if(currMax - currMin > limit) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};