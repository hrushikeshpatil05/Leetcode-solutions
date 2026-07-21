class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        queue<string>q;
        q.push(beginWord);
        unordered_set<string>mp(wordList.begin(),wordList.end());
        
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
                if(top == endWord) {
                    return level;
                }
                for(int i=0;i<top.size();i++) {
                    char originalChar = top[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == originalChar) continue;
                        top[i] = c;
                        if(mp.find(top) != mp.end()) {
                            q.push(top);
                            mp.erase(top);
                        }
                    }
                    top[i] = originalChar;
                }
            }
            level++;
        }
        return 0;
    }
};