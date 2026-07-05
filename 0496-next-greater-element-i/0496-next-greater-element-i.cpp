class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int>st;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int>ans;
        for(int i=0;i<nums1.size();i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                ans.push_back(mp[nums1[i]]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};