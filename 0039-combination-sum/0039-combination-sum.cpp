class Solution {
public:
    int n;

    void solve(int i, int target, vector<int>& candidates,
               vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= n || target < 0) {
            return;
        }
        temp.push_back(candidates[i]);
        solve(i, target - candidates[i], candidates, ans, temp);
        temp.pop_back();
        solve(i + 1, target, candidates, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, target, candidates, ans, temp);
        return ans;
    }
};