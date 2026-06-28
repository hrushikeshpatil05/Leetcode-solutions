class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>windowSum(n - k + 1, 0);
        int currSum = 0;
        for(int i=0;i<n;i++) {
            currSum += nums[i];

            if(i >= k) {
                currSum -= nums[i - k];
            }

            if(i >= k-1) {
                windowSum[i - k + 1] = currSum;
            }
        }

        vector<int>leftBest(n - k + 1, 0);
        int idx = 0;

        for(int i = 0; i<n-k+1; i++) {
            if(windowSum[i] > windowSum[idx]) {
                idx = i;
            }
            leftBest[i] = idx;
        }

        vector<int>rightBest(n - k + 1, 0);
        idx = n - k;

        for(int i = n-k; i >= 0; i--) {
            if(windowSum[i] >= windowSum[idx]) {
                idx = i;
            }
            rightBest[i] = idx;
        }

        vector<int>ans(3,0);
        int maxSum = -1;

        for(int i = k; i < windowSum.size() - k; i++) {
            int left = leftBest[i - k];
            int right = rightBest[i + k];

            int sum = windowSum[left] + windowSum[right] + windowSum[i];

            if(maxSum < sum) {
                maxSum = sum;
                ans = {left, i, right};
            }
        }

        return ans;
    }
};