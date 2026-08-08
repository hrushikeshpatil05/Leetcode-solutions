class Solution {
public:
    int n;
    int dp[1001][1001];
    int countSubstrings(string s) {
        n = s.size();
        memset(dp, 0, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            ans++;
            for (int j = 0; j < i; j++) {
                if(s[i] == s[j] && (i-j<=2 || dp[j+1][i-1])) {
                    ans++;
                    dp[j][i] = 1;
                }
            }
        }
        return ans;
    }
};