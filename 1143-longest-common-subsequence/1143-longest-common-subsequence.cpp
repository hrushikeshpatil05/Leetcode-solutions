class Solution {
public:
    int m, n;
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size(), n = text2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));

        vector<int>prevRow(n+1,0);
        vector<int>currRow(n+1,0);

        for(int i = 1; i<= m;i++) {
            for(int j=1;j<=n;j++) {
                if(text1[i-1] == text2[j-1]) {
                    currRow[j] = 1 + prevRow[j-1];
                }
                else {
                    currRow[j] = max(prevRow[j],currRow[j-1]);
                }
            }
            prevRow = currRow;
        }
        return prevRow[n];
    }
};