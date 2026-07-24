class Solution {
public:
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

    bool solve(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        if(idx == word.size()) {
            return true;
        }
        char originalChar = board[i][j];
        board[i][j] = '#';
        bool ans = false;
        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == word[idx]) {
                ans = ans || solve(nr,nc,idx+1,board,word);
            }
        }
        board[i][j] = originalChar;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0] && solve(i,j,1,board,word)) {
                    return true;
                }
            }
        }
        return false;
    }
};