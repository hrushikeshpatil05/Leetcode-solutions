class Solution {
public:
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int m,n;

    // int dfs(int i,int j, vector<vector<int>>& grid) {

    // }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        queue<pair<int,int>>q;
        int freshOranges = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        if(freshOranges == 0) {
            return 0;
        }
        int ct = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row,col] = q.front();
                q.pop();
                for(int k=0;k<4;k++) {
                    int nr = row + dir[k][0];
                    int nc = col + dir[k][1];

                    if(nr>=0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        freshOranges--;
                        if(freshOranges == 0) {
                            return ct;
                        }
                    }
                }
            }
            ct++;
        }
        return freshOranges ? -1 : ct;
    }
};