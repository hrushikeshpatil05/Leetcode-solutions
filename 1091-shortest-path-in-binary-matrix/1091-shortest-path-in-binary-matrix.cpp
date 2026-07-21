class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>>q;
        if(grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }
        int level = 1;
        q.push({0,0});

        // vector<vector<int>>vis(m,vector<int>(n,0));

        int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{-1,1},{1,0},{1,1},{0,1},{1,-1}};

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row,col] = q.front();
                q.pop();
                if(row == m - 1 && col == n - 1) {
                    return level;
                }
                // vis[row][col] = 1;

                for(int k=0;k<8;k++) {
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
        return -1;
    }
};