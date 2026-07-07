class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int>pq;
        int i = 0;
        while(i<n) {
            pq.push(nums[i++]);
        }
        
        int rem = k - 1;

        while(rem--) {
            pq.pop();
        }
        return pq.top();
    }
};