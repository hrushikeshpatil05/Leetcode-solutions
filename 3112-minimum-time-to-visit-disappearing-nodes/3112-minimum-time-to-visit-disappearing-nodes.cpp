class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];

        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(n,1e8);
        vis[0] = 0;

        while(!pq.empty()) {
            auto [time,node] = pq.top();
            pq.pop();

            if(vis[node] < time) {
                continue;
            }

            for(auto x:adj[node]) {
                int newNode = x.first;
                int newTime = time + x.second;
                if(vis[newNode] > newTime && newTime < disappear[newNode]) {
                    vis[newNode] = newTime;
                    pq.push({newTime,newNode});
                }
            }
        }

        vector<int>ans(n,-1);

        for(int i=0;i<n;i++) {
            if(vis[i] <= disappear[i]) {
                ans[i] = vis[i];
            }
        }
        return ans;
    }
};