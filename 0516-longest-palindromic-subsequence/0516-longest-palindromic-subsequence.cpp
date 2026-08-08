class Solution {
public:
    int n;
    int longestPalindromeSubseq(string s) {
        n = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        vector<int>prev(n+1,0);
        for(int i=1;i<=n;i++) {
            int prevDiag = 0;
            for(int j=1;j<=n;j++) {
                int temp = prev[j];
                if(rev[i-1] == s[j-1]) {
                    prev[j] = 1 + prevDiag;
                }
                else {
                    prev[j] = max(prev[j],prev[j-1]);
                }
                prevDiag = temp;
            }
        }
        return prev[n];
        // return solve(0,s,"");
    }
};