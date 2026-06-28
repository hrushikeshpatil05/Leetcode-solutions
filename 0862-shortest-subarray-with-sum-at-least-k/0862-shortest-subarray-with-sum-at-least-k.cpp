class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long>prefSum(n+1,0);

        for(int i=0;i<n;i++) {
            prefSum[i+1] = prefSum[i] + nums[i];
        }

        deque<int>dq;

        int ans = n+1;

        for(int right = 0; right <= n; right++) {
            
            while(!dq.empty() && prefSum[right] - prefSum[dq.front()] >= k) {
                ans = min(ans,right - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefSum[right] <= prefSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(right);
        }
        return ans == n+1 ? -1 : ans;
    }
};