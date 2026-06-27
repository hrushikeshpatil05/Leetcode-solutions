class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int left = 0;

        deque<int>maxDQ;
        deque<int>minDQ;

        for(int right = 0; right < n; right++) {
            while(!maxDQ.empty() && maxDQ.back() < nums[right] ) {
                maxDQ.pop_back();
            }

            maxDQ.push_back(nums[right]);

            while(!minDQ.empty() && minDQ.back() > nums[right]) {
                minDQ.pop_back();
            }

            minDQ.push_back(nums[right]);

            if(maxDQ.front() - minDQ.front() > limit) {
                if(maxDQ.front() == nums[left]) {
                    maxDQ.pop_front();
                }
                if(minDQ.front() == nums[left]) {
                    minDQ.pop_front();
                }
                left++;
            }
        }
        return n - left;
    }
};