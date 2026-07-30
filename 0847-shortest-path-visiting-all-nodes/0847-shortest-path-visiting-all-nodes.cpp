class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (auto x : graph[i]) {
                adj[i].push_back(x);
            }
        }

        int allVisitedNode = (1 << n) - 1;

        queue<pair<int, int>> pq;
        set<pair<int, int>> vis;

        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            pq.push({i, mask});
            vis.insert({i,mask});
        }
        int level = 0;

        while (!pq.empty()) {

            int size = pq.size();
            while (size--) {
                auto [node, path] = pq.front();
                pq.pop();

                if (path == allVisitedNode) {
                    return level;
                }

                for (auto x : adj[node]) {
                    int newNode = (1<<x);
                    int newPath = (path | newNode);
                    if (vis.find({x, newPath}) == vis.end()) {
                        pq.push({x, newPath});
                        vis.insert({x, newPath});
                    }
                }
            }
            level++;
        }
        return 0;
    }
};