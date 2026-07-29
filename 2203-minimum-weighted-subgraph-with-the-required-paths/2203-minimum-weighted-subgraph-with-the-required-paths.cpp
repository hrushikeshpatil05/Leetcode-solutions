class Solution {
public:
    void dijkstra(int startNode, vector<pair<int, long long>> adj[],
                  vector<long long>& dist) {

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, startNode});
        dist[startNode] = 0;

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (dist[node] < weight) {
                continue;
            }

            for (auto x : adj[node]) {
                int newNode = x.first;
                long long newWeight = weight + x.second;

                if (dist[newNode] > newWeight) {
                    dist[newNode] = newWeight;
                    pq.push({newWeight, newNode});
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1,
                            int src2, int dest) {
        vector<pair<int, long long>> adj1[n];
        vector<pair<int, long long>> adj2[n];
        long long maxEl = 1e10 + 1;

        vector<long long> dist1(n, maxEl);
        vector<long long> dist2(n, maxEl);
        vector<long long> dist3(n, maxEl);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2];
            adj1[u].push_back({v, w});
            adj2[v].push_back({u, w});
        }

        dijkstra(src1, adj1, dist1);
        dijkstra(src2, adj1, dist2);
        dijkstra(dest, adj2, dist3);

        long long ans = maxEl;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != maxEl && dist2[i] != maxEl && dist3[i] != maxEl) {
                ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
            }
        }

        return ans == maxEl ? -1 : ans;
    }
};