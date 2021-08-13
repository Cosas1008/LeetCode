/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root, targetSum, ans, {});
        return ans;
    }
    void helper(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> cur){
        if(!root) return;
        cur.push_back(root->val);
        target -= root->val;
        if(target == 0 && !root->left && !root->right){ // find
            ans.push_back(cur);
        }else{
            if(root->left) helper(root->left, target, ans, cur);
            if(root->right) helper(root->right, target, ans, cur);
        }
    }
};