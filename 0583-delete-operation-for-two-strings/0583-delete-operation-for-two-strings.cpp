class Solution {
public:
    int m,n;
    int dp[501][501];
    int solve(int i,int j,string& word1,string& word2) {
        if(i>m || j>n) {
            return 1e8;
        }

        if(i == m) {
            return n-j;
        }

        if(j == n) {
            return m - i;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int take = 1e8;
        if(word1[i] == word2[j]) {
            take = solve(i+1,j+1,word1,word2);
        }
        int deleteChar1 = 1 + solve(i+1,j,word1,word2);
        int deleteChar2 = 1 + solve(i,j+1,word1,word2);

        return dp[i][j] = min({take,deleteChar1,deleteChar2});
    }
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};