class Solution {
public:
    int m, n;
    int minDistance(string word1, string word2) {
        m = word1.size(), n = word2.size();

        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);

        for(int j=0;j<=n;j++) {
            next[j] = n-j;
        }

        for (int i = m - 1; i >= 0; i--) {
            int prevDiag = next[n];
            next[n] = m - i;
            for (int j = n - 1; j >= 0; j--) {
                int temp = next[j];
                if (word1[i] == word2[j]) {
                    next[j] = prevDiag;
                }
                else {
                    next[j] = 1 + min(next[j],next[j+1]);
                }
                prevDiag = temp;
            }
        }
        return next[0];
    }
};