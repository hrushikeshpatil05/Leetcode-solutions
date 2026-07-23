class Solution {
public:
    int n;
    void solve(int i,vector<int>& nums, vector<vector<int>>& ans) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }
        for(int idx = i; idx < n ; idx++) {
            swap(nums[idx],nums[i]);
            solve(i+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }
};