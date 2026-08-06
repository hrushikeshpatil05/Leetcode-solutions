class Solution {
public:
    int m,n;
    int maxAreaOfHistogram(vector<int>& heights) {
        stack<int>st;
        int maxArea = 0;

        for(int i=0;i<=n;i++) {
            int currHeight = i == n ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int rightB = i;
                int leftB = st.empty() ? -1 : st.top();
                int w = rightB - leftB - 1;

                maxArea = max(maxArea,h*w);
            }
            st.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int maxArea = 0;
        vector<int>heights(n,0);

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
               if(matrix[i][j] == '1') {
                heights[j]++;
               }
               else {
                heights[j] = 0;
               }
            }
            maxArea = max(maxArea,maxAreaOfHistogram(heights));
        }
        
        return maxArea;
    }
};