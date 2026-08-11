/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int left, int right) {
        vector<TreeNode*> currTrees;
        if (left > right) {
            currTrees.push_back(nullptr);
            return currTrees;
        }

        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftSubtree = solve(left, i - 1);
            vector<TreeNode*> rightSubtree = solve(i + 1, right);

            for (auto leftNode : leftSubtree) {
                for (auto rightNode : rightSubtree) {
                    TreeNode* root = new TreeNode(i);

                    root->left = leftNode;
                    root->right = rightNode;

                    currTrees.push_back(root);
                }
            }
        }
        return currTrees;
    }
    vector<TreeNode*> generateTrees(int n) { return solve(1, n); }
};