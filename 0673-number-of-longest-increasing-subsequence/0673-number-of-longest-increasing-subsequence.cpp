class Solution {
public:
    int n;
    int findNumberOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);

        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    } else if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLength = max(maxLength, length[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                ans += count[i];
            }
        }
        return ans;
    }
};