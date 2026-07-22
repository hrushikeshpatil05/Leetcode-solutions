class Solution {
public:
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    bool solve(int i, int j, vector<vector<char>>& board, string& word, int idx,vector<vector<int>>& vis) {
        if(idx == word.size()) {
            return true;
        }
        vis[i][j] = 1;
        bool ans = false;
        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == word[idx] && !vis[nr][nc]) {
                ans = ans | solve(nr,nc,board,word,idx+1,vis);
            }
        }
        idx--;
        vis[i][j] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

            vector<vector<int>>vis(m,vector(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0] && solve(i,j,board,word,1,vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};