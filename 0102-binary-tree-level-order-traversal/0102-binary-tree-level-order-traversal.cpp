/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        int levelCt = 1;
        while(!q.empty()) {
            vector<int>temp;
            int currCt = levelCt;
            int nextCt = 0;
            while(currCt--) {
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left) {
                    q.push(top->left);
                    nextCt++;
                }
                if(top->right) {
                    q.push(top->right);
                    nextCt++;
                }
            }
            ans.push_back(temp);
            levelCt = nextCt;
        }
        return ans;
    }
};