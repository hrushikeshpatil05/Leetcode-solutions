class Solution {
public:
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    void dfs(int i, int j, vector<vector<char>>& board) {
        board[i][j] = 'z';

        for(int k=0;k<4;k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                dfs(nr,nc,board);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i=0;i<m;i++) {
            if(board[i][0] == 'O') {
                dfs(i,0,board);
            }
            if(board[i][n-1] == 'O') {
                dfs(i,n-1,board);
            }
        }

        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(0,j,board);
            }
            if(board[m-1][j] == 'O') {
                dfs(m-1,j,board);
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 'z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};