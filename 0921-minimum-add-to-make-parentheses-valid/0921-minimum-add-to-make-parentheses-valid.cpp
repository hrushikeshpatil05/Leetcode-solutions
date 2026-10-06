class Solution {
public:
    int minAddToMakeValid(string s) {
        int openingBraces = 0;
        int closingBraces = 0;

        int n  = s.size();

        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                openingBraces++;
            }
            else {
                if(openingBraces > 0) {
                    openingBraces--;
                }
                else {
                    closingBraces++;
                }
            }
        }
        return openingBraces + closingBraces;
    }
};