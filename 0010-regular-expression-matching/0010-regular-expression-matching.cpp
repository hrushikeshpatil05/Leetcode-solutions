class Solution {
public:
    int n,m;
    int dp[21][21];
    bool solve(int i,int j,string& s,string& p) {
        if (j >= m) {
            return i >= n;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i<n) && (s[i] == p[j] || p[j] == '.');
        
        if(j+1 < m && p[j+1] == '*') {
            bool leave = solve(i,j+2,s,p);
            bool take = match && solve(i+1,j,s,p);
            return dp[i][j] = leave | take;
        }
        else {
            return dp[i][j] = match && solve(i+1,j+1,s,p);
        }
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
    }
};