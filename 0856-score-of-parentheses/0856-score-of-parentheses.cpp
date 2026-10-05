class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();

        stack<int>st;
        st.push(0);

        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push(0);
            }
            else {
                int innerScore = st.top();
                st.pop();
                
                int calScore = innerScore == 0 ? 1 : innerScore*2;

                st.top() += calScore;
                
            }
        }
        return st.top();
    }
};