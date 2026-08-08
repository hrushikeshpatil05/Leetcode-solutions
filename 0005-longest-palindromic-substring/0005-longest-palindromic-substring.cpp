class Solution {
public:
    int n;
    int dp[1001][1001];
    bool solve(int i,int j,string& s) {
        if(i>=j) {
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == s[j]) {
            return dp[i][j] = solve(i+1,j-1,s);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        n = s.size();

        memset(dp,-1,sizeof(dp));

        int startidx = 0;
        string ans = "";
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(solve(i,j,s) && ans.size() < (j-i+1)) {
                    // startIdx = i;
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;

    }
};