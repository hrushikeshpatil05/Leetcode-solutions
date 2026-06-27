class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int left = 0;
        int currCost = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            int diff = abs(s[i] - t[i]);
            currCost += diff;

            while(currCost > maxCost && left <= i) {
                currCost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};