class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        vector<int>diff(n,0);

        int left = 0;
        int currCost = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            diff[i] = abs(s[i] - t[i]);
            currCost += diff[i];

            while(currCost > maxCost && left <= i) {
                currCost -= diff[left];
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};