class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>>dist(m+1,vector<int>(n+1,1e8));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});

        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()) {
            auto [cost,top] = pq.top();
            pq.pop();
            auto [i,j] = top;

            if(dist[i][j] < cost) {
                continue;
            }

            if(i == m - 1 && j == n - 1) {
                return cost;
            }

            for(int k=0;k<4;k++) {
                int r = i + dir[k][0];
                int c = j + dir[k][1];
                if(r >= 0 && r < m && c >= 0 && c < n) {
                    int newCost = cost;
                    if(k == grid[i][j] - 1) {
                        newCost += 0;
                    }
                    else {
                        newCost += 1;
                    }

                    if(newCost < dist[r][c]) {
                        pq.push({newCost,{r,c}});
                        dist[r][c] = newCost;
                    }
                }
            }
        }
        return 0;
    }
};