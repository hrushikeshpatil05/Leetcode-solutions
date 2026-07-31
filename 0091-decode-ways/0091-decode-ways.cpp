class Solution {
public:
    int n;
    // int solve(int i,string& s,vector<int>& dp) {
    //     if(i>=n) {
    //         return 1;
    //     }

    //     if(s[i] == '0') return 0;

    //     if(dp[i] != -1) {
    //         return dp[i];
    //     }

    //     int ways = solve(i+1,s,dp);

    //     if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
    //         ways += solve(i+2,s,dp);
    //     }

    //     return dp[i] = ways;
    // }
    int numDecodings(string s) {
        n = s.size();
        vector<int> dp(n + 1, 0);
        if (s[0] == '0') {
            return 0;
        }
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
                if (i + 1 < n &&
                    (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
        // return solve(0,s,dp);
    }
};