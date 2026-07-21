class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        queue<string>q;
        q.push(beginWord);
        unordered_map<string,int>mp;
        for(auto x:wordList) {
            mp[x]++;
        }
        
        if(mp.find(beginWord) != mp.end()) {
            mp.erase(beginWord);
        }

        if(mp.find(endWord) == mp.end()) {
            return 0;
        }

        int level = 1;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto top = q.front();
                q.pop();
                for(int i=0;i<top.size();i++) {
                    string curr = top;
                    for(char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        if(curr == endWord) {
                            return level + 1;
                        }
                        if(mp.find(curr) != mp.end()) {
                            q.push(curr);
                            mp.erase(curr);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};