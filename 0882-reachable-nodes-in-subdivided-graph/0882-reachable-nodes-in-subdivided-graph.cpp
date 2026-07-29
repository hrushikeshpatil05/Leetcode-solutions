class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int,int>>adj[n+1];

        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w+1});
            adj[v].push_back({u,w+1});
        }

        vector<int>moves(n+1,2e9);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        moves[0] = 0;

        while(!pq.empty()) {
            auto [nodes,currNode] = pq.top();
            pq.pop();

            if(nodes > moves[currNode]) {
                continue;
            }

            for(auto x:adj[currNode]) {
                int bNodes = x.second;
                int newNode = x.first;

                if(moves[currNode] + bNodes < moves[newNode]) {
                    moves[newNode] = bNodes + moves[currNode];
                    pq.push({moves[newNode],newNode});
                }
                
            }
        }
        
        int ans = 0;

        for(int i=0;i<n;i++) {
            if(moves[i] <= maxMoves) {
                ans++;
            }
        }

        for(auto x:edges) {
            int u = x[0];
            int v = x[1];
            int ct = x[2];

            int from_u = max(0,maxMoves - moves[u]);
            int from_v = max(0,maxMoves - moves[v]);

            ans += min(ct,from_u+from_v);
        }
        return ans;
    }
};