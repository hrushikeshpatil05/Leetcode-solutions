class Solution {
public:
    int n,m;
    int dp[2001][2001];
    bool solve(int i,int j,string& s,string& p) {
        if(i>=n && j>=m) {
            return true;
        }

        if(j>=m && i<n) {
            return false;
        }

        if(i>=n && j<m) {
            while(j<m) {
                if(p[j] != '*') {
                    return false;
                }
                j++;
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i+1,j+1,s,p);
        } 
        
        if(p[j] == '*') {
            return dp[i][j] = solve(i+1,j,s,p) || solve(i,j+1,s,p);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p);
    }
};