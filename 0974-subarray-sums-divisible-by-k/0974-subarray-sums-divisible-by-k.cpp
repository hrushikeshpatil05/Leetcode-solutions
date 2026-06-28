class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int>remCt(k,0);
        remCt[0] = 1;

        int currSum = 0;
        int ans = 0;
        for(int right = 0; right < n; right++) {
            currSum += nums[right];

            int rem = (currSum%k + k)%k;

            ans += remCt[rem];

            remCt[rem]++;
        }
        return ans;
    }
};