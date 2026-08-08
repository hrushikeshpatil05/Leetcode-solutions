class Solution {
public:
    int n;
    int solve(int i,int j,string& s) {
        int count = 0;
        while(i>=0 && j<n && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        n = s.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += solve(i,i,s);
            ans += solve(i,i+1,s);
        }
        return ans;
    }
};