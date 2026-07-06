class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        stack<int>st;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[st.top()] < height[i]) {
                
                int mid = st.top();
                st.pop();

                if(st.empty()) break;

                int left = st.top();
                int right = i;

                int width = right - left - 1;

                int temp = min(height[left], height[right]) - height[mid];
                ans += width*temp;
            }
            st.push(i);
        }
        return ans;
    }
};