class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;

        int ans = 0;

        for(int i=0;i<=n;i++) {
            int currHeight = i == n ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > currHeight) {
                int height = heights[st.top()];
                st.pop();

                int rightB = i;
                int leftB = st.empty() ? -1 : st.top();

                int width = (rightB - leftB) - 1;
                ans = max(ans, height*width);
            }
            st.push(i);
        }
        return ans;
    }
};