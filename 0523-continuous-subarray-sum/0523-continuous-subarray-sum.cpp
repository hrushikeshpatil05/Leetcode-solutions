class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>reminderMap;

        reminderMap[0] = -1;
        int currSum = 0;
        for(int i=0;i<n;i++) {
            currSum += nums[i];

            int reminder = currSum%k;

            if(reminderMap.find(reminder) != reminderMap.end()) {
                if(i - reminderMap[reminder] >= 2) {
                    return true;
                }
            }
            reminderMap[reminder] = i;
        }
        return false;
    }
};