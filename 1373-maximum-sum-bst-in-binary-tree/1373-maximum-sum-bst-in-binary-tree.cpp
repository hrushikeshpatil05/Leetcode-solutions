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

struct NodeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};
class Solution {
public:
    int maxSum = 0;
    NodeInfo solve(TreeNode* root) {
        if(!root) {
            return {true,INT_MAX,INT_MIN,0};
        }

        NodeInfo lh = solve(root->left);
        NodeInfo rh = solve(root->right);

        if(lh.isBST && rh.isBST && root->val < rh.minVal && root->val > lh.maxVal) {
            int currSum = root->val + lh.sum + rh.sum;

            maxSum = max(maxSum,currSum);

            return {
                true,
                min(root->val,lh.minVal),
                max(root->val,rh.maxVal),
                currSum
            };
        }

        return {false,INT_MAX,INT_MIN,0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};