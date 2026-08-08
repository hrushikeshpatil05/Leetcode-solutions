class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int>curr(n+1,1e8);
        vector<int>next(n+1,1e8);

        for(int i=0;i<=n;i++) {
            next[i] = n-i;
        }
        for(int i=m-1;i>=0;i--) {
            curr[n] = m - i;
            for(int j=n-1;j>=0;j--) {
                if(word1[i] == word2[j]) {
                    curr[j] = next[j+1];
                }
                else {
                    int deleteChar = 1 + next[j];
                    int insertChar = 1 + curr[j+1];
                    int replaceChar = 1 + next[j+1];
                    curr[j] = min({deleteChar,insertChar,replaceChar});
                }
            }
            next = curr;
        }
        return next[0];
    }
};