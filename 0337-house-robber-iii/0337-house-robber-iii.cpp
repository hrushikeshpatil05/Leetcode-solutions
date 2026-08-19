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
    pair<int,int> solve(TreeNode* root) {
        if(!root) {
            return {0,0};
        }

        pair<int,int> leftChoices = solve(root->left);
        pair<int,int> rightChoices = solve(root->right);

        int robCurrent = root->val + leftChoices.second + rightChoices.second;

        int leaveCurrent = max(leftChoices.first,leftChoices.second) + max(rightChoices.first,rightChoices.second);

        return {robCurrent,leaveCurrent};
    }
    int rob(TreeNode* root) {
        pair<int,int>result = solve(root);
        return max(result.first,result.second);
    }
};