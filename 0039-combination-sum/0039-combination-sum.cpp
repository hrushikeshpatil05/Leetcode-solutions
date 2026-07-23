class Solution {
public:
    int n;

    void solve(int i, int target, int sum, vector<int>& candidates,
               set<vector<int>>& s, vector<int>& temp) {
        if (target == sum) {
            s.insert(temp);
            return;
        }
        if (i >= n) {
            return;
        }
        if (sum + candidates[i] <= target) {
            sum += candidates[i];
            temp.push_back(candidates[i]);
            solve(i, target, sum, candidates, s, temp);
            solve(i + 1, target, sum, candidates, s, temp);
            temp.pop_back();
            sum -= candidates[i];
        }
        solve(i + 1, target, sum, candidates, s, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        set<vector<int>> s;
        solve(0, target, 0, candidates, s, temp);
        vector<vector<int>> ans;
        for (auto x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};