class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int>dp;
        vector<int>ans(n);

        for(int i=0;i<n;i++) {
            int h = obstacles[i];

            auto it = upper_bound(dp.begin(),dp.end(),h);

            if(it == dp.end()) {
                dp.push_back(h);
                ans[i] = dp.size();
            }
            else {
                *it = h;
                ans[i] = (it - dp.begin()) + 1;
            }
        }
        return ans;  
    }
};