class Solution {
public:
    int size;
    void solve(int open, int close, vector<string>& ans, string& temp) {
        if(temp.size() == 2*size) {
            ans.push_back(temp);
            return;
        }
        if(open < size) {
            temp.push_back('(');
            solve(open+1,close,ans,temp);
            temp.pop_back();
        }
        if(close < open) {
            temp.push_back(')');
            solve(open,close+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        size = n;
        vector<string>ans;
        string temp = "";
        solve(0,0,ans,temp);
        return ans;
    }
};