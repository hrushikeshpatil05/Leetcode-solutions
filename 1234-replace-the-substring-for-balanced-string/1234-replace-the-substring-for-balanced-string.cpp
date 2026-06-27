class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int reqSize = n/4;
        unordered_map<char,int>freq;

        for(int i=0;i<n;i++) {
            freq[s[i]]++;
        }

        if(freq['Q'] == reqSize && freq['W'] == reqSize && freq['E'] == reqSize && freq['R'] == reqSize) {
            return 0;
        } 

        int left = 0;
        int right = 0;

        int ans = n;

        while(right < n) {
            freq[s[right]]--;

            while(left <= right && freq['Q'] <= reqSize && freq['W'] <= reqSize && freq['E'] <= reqSize && freq['R'] <= reqSize) {
                ans = min(ans,right - left + 1);

                freq[s[left]]++;
                left++;
            }
            right++;
        }
        return ans;
    }
};