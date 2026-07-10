class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        sort(trips.begin(),trips.end(),[](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({trips[0][2], trips[0][0]});
        int currCap = trips[0][0];

        if (currCap > capacity) {
            return false;
        }

        for (int i = 1; i < n; i++) {
            while (!pq.empty() && trips[i][1] >= pq.top().first) {
                currCap -= pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2], trips[i][0]});
            currCap += trips[i][0];
            if (currCap > capacity) {
                return false;
            }
        }
        return true;
    }
};