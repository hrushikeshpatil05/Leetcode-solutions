class Solution {
public:
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    bool solve(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        if(idx == word.size()) {
            return true;
        }
        auto temp = board[i][j];
        board[i][j] = '#';
        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == word[idx]) {
                if(solve(nr,nc,board,word,idx+1)) {
                    return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0] && solve(i,j,board,word,1)) {
                    return true;
                }
            }
        }
        return false;
    }
};