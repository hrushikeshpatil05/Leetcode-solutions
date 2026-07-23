class Solution {
public:
    int n;
    vector<string>number = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int i, string& digits, vector<string>& res, string& curr) {
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }
        
        int digit = (digits[i] - '0');
        string letter = number[digit-2];

        for(auto x: letter) {
            curr.push_back(x);
            solve(i+1,digits,res,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        vector<string>res;
        string curr = "";
        solve(0,digits,res,curr);
        return res;
    }
};