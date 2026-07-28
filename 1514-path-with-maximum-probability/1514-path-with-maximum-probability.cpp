class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n+1];

        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        double ans = 0.0000;

        vector<double>prob(n+1,0);

        priority_queue<pair<double,int>>pq;
        pq.push({1.000,start_node});
        prob[start_node] = 1.000;

        while(!pq.empty()) {
            auto [p,node] = pq.top();
            // cout<<p<<endl;
            pq.pop();

            if(node == end_node) {
                return p;
            }

            if(prob[node] > p) {
                continue;
            }

            for(auto x:adj[node]) {
                // cout<<p<<" "<<x.second<<endl;
                double newProb = p * x.second;
                int newNode = x.first;
                // cout<<newNode<<" "<<newProb<<endl;
                if(newProb > prob[newNode]) {
                    prob[newNode] = newProb;
                    pq.push({newProb,newNode});
                }
            }
        }
        return ans;
    }
};