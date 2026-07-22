class Solution {
public:
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int i,int j, vector<vector<int>>& grid) {
        grid[i][j] = 1;

        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 0) {
                dfs(nr,nc,grid);
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0;i<m;i++) {
            if(grid[i][0] == 0) {
                dfs(i,0,grid);
            }
            if(grid[i][n-1] == 0) {
                dfs(i,n-1,grid);
            }
        }

        for(int j=0;j<n;j++) {
            if(grid[0][j] == 0) {
                dfs(0,j,grid);
            }
            if(grid[m-1][j] == 0) {
                dfs(m-1,j,grid);
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};