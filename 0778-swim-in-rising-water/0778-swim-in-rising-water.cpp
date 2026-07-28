class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>>cost(m,vector<int>(n,1e8));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});

        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

        while(!pq.empty()) {
            auto [t, top] = pq.top();
            pq.pop();
            auto [i,j] = top;

            if(i == m-1 && j == n-1) {
                return t;
            }

            if(cost[i][j] < t) {
                continue;
            }

            for(int k=0;k<4;k++) {
                int nr = i + dir[k][0];
                int nc = j + dir[k][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int timeTaken = max(t,grid[nr][nc]);
                    if(cost[nr][nc] > timeTaken) {
                        cost[nr][nc] = timeTaken;
                        pq.push({timeTaken,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};