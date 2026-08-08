class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        vector<int>next(n+1,0);
        vector<int>curr(n+1,0);

        for(int j=n-1;j>=0;j--) {
            next[j] = next[j+1] + s2[j];
        }

        for(int i=m-1;i>=0;i--) {
            curr[n] = next[n] + s1[i];
            for(int j=n-1;j>=0;j--) {
                if(s1[i] == s2[j]) {
                    curr[j] = next[j+1];
                }
                else {
                    curr[j] = min((int)s1[i] + next[j] , (int)s2[j] + curr[j+1]);
                }
            }
            next = curr;
        }
        return next[0];
    }
};