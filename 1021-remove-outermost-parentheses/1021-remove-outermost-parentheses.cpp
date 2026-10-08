class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int>st;
        int ctOp = 0;
        int ctCl = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                st.push(i);
                ctOp++;
            }
            else {
                st.push(i);
                ctCl++;

                if(ctOp == ctCl) {
                    st.pop();

                    string temp = "";

                    while(!st.empty()) {
                        temp+= s[st.top()];
                        st.pop();
                    }
                    temp.pop_back();
                    reverse(temp.begin(),temp.end());
                    ans += temp;

                    ctOp = 0;
                    ctCl = 0;
                }
            } 
        }

        return ans;
    }
};