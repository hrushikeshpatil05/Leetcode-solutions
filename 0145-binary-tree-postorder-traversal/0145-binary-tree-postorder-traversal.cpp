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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        if(!root) {
            return result;
        }

        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        
        stack<TreeNode*>st;

        while(!st.empty() || curr) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* top = st.top();

                if(top->right && top->right != prev) {
                    curr = top->right;
                }
                else {
                    result.push_back(top->val);
                    prev = top;
                    st.pop();
                }
            }
        }
        return result;
    }
};