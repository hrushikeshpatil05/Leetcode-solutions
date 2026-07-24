class Solution {
public:
    bool isValid(vector<string>& temp, int row, int col, int n) {
        int currCol = col, currRow = row;
        while(currRow >= 0 && currCol < n) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currRow--;
            currCol++;
        }
        currCol = col;
        currRow = row;
        while(currCol < n) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currCol++;
        }
        currCol = col;
        while(currRow < n && currCol < n) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currRow++;
            currCol++;
        }
        currRow = row;
        currCol = col;
        while(currRow < n) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currRow++;
        }
        currRow = row;
        while(currRow < n && currCol >= 0) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currRow++;
            currCol--;
        }
        currRow = row;
        currCol = col;
        while(currCol >= 0) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currCol--;
        }
        currCol = col;
        while(currRow >= 0 && currCol >= 0) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currRow--;
            currCol--;
        }
        currRow = row;
        currCol = col;
        while(currRow >= 0) {
            if(temp[currRow][currCol] == 'Q') {
                return false;
            }
            currRow--;
        }
        return true;
    }
    void solve(int col,int n, vector<vector<string>>& ans, vector<string>& temp) {
        if(col == n) {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++) {
            if(isValid(temp,row,col,n)) {
                temp[row][col] = 'Q';
                solve(col+1,n,ans,temp);
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++) {
            temp[i] = s;
        }
        solve(0,n,ans,temp);
        return ans;
    }
};