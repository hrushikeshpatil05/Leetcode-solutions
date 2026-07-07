class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = (x*x + y*y);
            pq.push({dist,i});
        }

        vector<vector<int>>ans;

        while(k--) {
            auto top = pq.top();
            pq.pop();

            ans.push_back(points[top.second]);
        }

        return ans;
    }
};