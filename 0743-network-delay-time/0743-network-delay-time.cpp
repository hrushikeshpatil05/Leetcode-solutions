class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int size = times.size();

        vector<pair<int,int>>adj[n+1];

        for(int i=0;i<size;i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,1e8);
        dist[k] = 0;
        int maxTime = 0;
        while(!pq.empty()) {
            auto [w,node] = pq.top();
            pq.pop();

            if(dist[node] < w) {
                continue;
            }

            for(auto x:adj[node]) {
                if(x.second + dist[node] < dist[x.first]) {
                    dist[x.first] = x.second + dist[node];
                    pq.push({x.second+dist[node],x.first});
                }
            }
        }

        for(int i=1;i<=n;i++) {
            if(dist[i] == 1e8) {
                return -1;
            }
            else {
                maxTime = max(maxTime,dist[i]);
            }
        }
        return maxTime;

    }
};