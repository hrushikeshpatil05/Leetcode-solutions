class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];
            adj[u].push_back({v, d});
        }

        queue<pair<int, pair<int, int>>> pq;

        vector<int> dist(n + 1, 1e8);

        pq.push({0, {src, 0}});
        dist[src] = 0;

        while (!pq.empty()) {
            int size = pq.size();
            for (int i = 0; i < size; i++) {
                auto [d, top] = pq.front();
                pq.pop();
                auto [node, stops] = top;

                if (stops > k) {
                    continue;
                }

                for (auto x : adj[node]) {
                    int newDist = d + x.second;
                    int newNode = x.first;
                    if (dist[newNode] > newDist) {
                        dist[newNode] = newDist;
                        pq.push({newDist, {newNode, stops + 1}});
                    }
                }
            }
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};