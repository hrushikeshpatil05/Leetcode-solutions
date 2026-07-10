class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int n = points.size();

        int ans = n;
        int prevEnd = points[0][1];
        for(int i=1;i<n;i++) {
            if(prevEnd >= points[i][0]) {
                ans--;
                prevEnd = min(prevEnd, points[i][1]);
            }
            else {
                prevEnd = points[i][1];
            }
        }
        return ans;
    }
};