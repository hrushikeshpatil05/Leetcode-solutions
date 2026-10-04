class Solution {
public:
    int n;
    bool checkValidString(string s) {
        n = s.size();
        stack<int> starIndex;
        stack<int> stackIndex;

        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (!starIndex.size() && !stackIndex.size()) {
                    return false;
                }
                if (!stackIndex.empty()) {
                    stackIndex.pop();
                } else {
                    starIndex.pop();
                }
            } else {
                if (s[i] == '(') {
                    stackIndex.push(i);
                } else {
                    starIndex.push(i);
                }
            }
        }

        if(stackIndex.size() == 0) {
            return true;
        }

        while (!starIndex.empty() && !stackIndex.empty()) {
            
            if (starIndex.top() < stackIndex.top()) {
                return false;
            }
            
            starIndex.pop();
            stackIndex.pop();
        }
        
        return stackIndex.empty();

        // return solve(0,s,st);
    }
};