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

class info {
    public:
        int maxValue;
        int minValue;
        int sum;
        bool isBST;
};
class Solution {
public:
    // int sumOfNodes(TreeNode* root) {
    //     if(!root) {
    //         return 0;
    //     }
    //     return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
    // }
    // bool isBST(TreeNode* root, int minValue, int maxValue) {
    //     if(!root) {
    //         return true;
    //     }
    //     if((root->val <= minValue || root->val >= maxValue) || (root->left && root->left->val >= root->val) || (root->right && root->right->val <= root->val)) {
    //         return false;
    //     }
    //     return isBST(root->left,minValue,root->val) & isBST(root->right,root->val,maxValue);
    // }
    info solve(TreeNode* root,int &maxSum) {
        if(!root) {
            return {INT_MIN,INT_MAX,0,1};
        }
        info left = solve(root->left,maxSum);
        info right = solve(root->right,maxSum);

        info currRoot;
        currRoot.maxValue = max(root->val,right.maxValue);
        currRoot.minValue = min(root->val,left.minValue);
        currRoot.sum = root->val + left.sum + right.sum;
        currRoot.isBST = (left.isBST & right.isBST & (root->val > left.maxValue && root->val < right.minValue));
        if(currRoot.isBST) {
            maxSum = max(maxSum, currRoot.sum); 
        }
        return currRoot;
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info temp = solve(root,maxSum);
        return maxSum;
    }
};