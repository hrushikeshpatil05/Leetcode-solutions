class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>>q;
        int level = -1;

        int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }

        if(q.empty() || q.size() == n*m) {
            return -1;
        }

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row,col] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nr = row + dir[k][0];
                    int nc = col + dir[k][1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr,nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            level++;
        }
        return level;
    }
};