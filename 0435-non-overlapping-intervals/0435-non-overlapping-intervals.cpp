class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int ans = 0;
        // int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        for(int i=1;i<n;i++) {
            if(prevEnd > intervals[i][0]) {
                ans++;
                if(prevEnd > intervals[i][1]) {
                    prevEnd = intervals[i][1];
                    // prevStart = intervals[i][0];
                }
            }
            else {
                // prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};