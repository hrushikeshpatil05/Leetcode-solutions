class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        
        unordered_map<char,int>mp;
        int left = 0;
        int ans = 0;
        int maxCt = 0;
        for(int right = 0; right < n; right++) {
            mp[s[right]]++;
            maxCt = max(maxCt, mp[s[right]]);

            while((right - left + 1) - maxCt > k) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};