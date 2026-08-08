class Solution {
public:
    int n;
    string solve(int i,int j,string& s) {
        while(i>=0 && j<n && s[i] == s[j]) {
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        n = s.size();

        if(n<=1) {
            return s;
        }
        
        string ans = "";
        for(int i=0;i<n-1;i++) {
            string odd = solve(i,i,s);
            string even = solve(i,i+1,s);

            if(odd.size() > ans.size()) {
                ans = odd;
            }
            if(even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    }
};