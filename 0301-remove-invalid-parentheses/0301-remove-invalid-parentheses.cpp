class Solution {
public:
    int n;
    unordered_set<string>ans;
    void solve(int i, string& s, int opBraces, int clBraces, string& temp,int balance) {
        if (balance < 0) return;
        if (i >= n) {
            if (opBraces == 0 && clBraces == 0 && balance == 0) {
                ans.insert(temp);
            }
            return;
        }

        if (s[i] == '(' && opBraces > 0) {
            solve(i + 1, s, opBraces - 1, clBraces, temp,balance);
        } else if (s[i] == ')' && clBraces > 0) {
            solve(i + 1, s, opBraces, clBraces - 1, temp,balance);
        }
        

        temp += s[i];
        
        if(s[i] == '(') {
            solve(i+1,s,opBraces,clBraces,temp,balance+1);
        }
        else if(s[i] == ')') {
            solve(i+1,s,opBraces,clBraces,temp,balance-1);
        }
        else {
            solve(i+1,s,opBraces,clBraces,temp,balance);
        }
        temp.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int noOfOpeningBraces = 0;
        int noOfClosingBraces = 0;

        n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                noOfOpeningBraces++;
            } else if (s[i] == ')') {
                if (noOfOpeningBraces > 0) {
                    noOfOpeningBraces--;
                } else {
                    noOfClosingBraces++;
                }
            }
        }

        cout << noOfOpeningBraces << " " << noOfClosingBraces << endl;
        string temp = "";
        solve(0, s, noOfOpeningBraces, noOfClosingBraces, temp,0);
        vector<string>res;

        for(auto x:ans) {
            res.push_back(x);
        }
        
        return res;
    }
};