class Solution {
public:
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i>=m || i<0 || j<0 || j>=n) {
            return 0;
        }

        grid[i][j] = 0;

        int take = 1;
        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                take += dfs(nr,nc, grid);
            }
        }
        return take;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxArea = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i,j,grid));
                }
            }
        }
        return maxArea;
    }
};