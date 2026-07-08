class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {

            while (i < n && prevEnd >= intervals[i][0]) {
                prevEnd = max(prevEnd, intervals[i][1]);
                i++;
            }
            ans.push_back({prevStart, prevEnd});
            if (i < n) {
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
            else {
                prevStart = -1;
                prevEnd = -1;
            }
        }
        if(prevStart != -1) {
            ans.push_back({prevStart,prevEnd});
        }
        return ans;
    }
};