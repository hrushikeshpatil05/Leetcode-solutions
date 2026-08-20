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
    int maxSum;
    int solve(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int leftNode = max(0,solve(root->left));
        int rightNode = max(0,solve(root->right));

        int currPeakSum = root->val + leftNode + rightNode;

        maxSum = max(maxSum,currPeakSum);

        return root->val + max(leftNode,rightNode);
    }
    int maxPathSum(TreeNode* root) {
        
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};