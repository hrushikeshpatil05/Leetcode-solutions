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
    int solve(TreeNode* root, bool isPrevRobbed,map<pair<TreeNode*,bool>,int>& mp) {
        if(!root) {
            return 0;
        }

        if(mp.find({root,isPrevRobbed}) != mp.end()) {
            return mp[{root,isPrevRobbed}];
        }

        int nottake = solve(root->left,false,mp) + solve(root->right,false,mp);
        int take = 0;
        if(!isPrevRobbed) {
            take = root->val + solve(root->left,true,mp) + solve(root->right,true,mp);

        }
        return mp[{root,isPrevRobbed}] = max(take,nottake);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int>mp;
        return solve(root,false,mp);
    }
};