class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    void solve(int i, int j, vector<vector<int>>& heights,vector<vector<int>>& vis) {
        if(i < 0 || j<0 || i>=n || j>=m) {
            return;;
        }

        if(vis[i][j]) return;

        vis[i][j] = 1;

        for(int k = 0; k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];

            if(nr>=0 && nr <n && nc>=0 && nc<m && heights[nr][nc] >= heights[i][j] && !vis[nr][nc]) {
                solve(nr,nc,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            solve(i,0,heights,pacific);
            solve(i,m-1,heights,atlantic);
        }

        for(int j=0;j<m;j++) {
            solve(0,j,heights,pacific);
            solve(n-1,j,heights,atlantic);
        }

        vector<vector<int>>ans;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};