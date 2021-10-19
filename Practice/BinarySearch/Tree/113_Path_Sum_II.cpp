/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, {});
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, vector<int> cur){
        if(!root) return;
        cur.push_back(root->val);
        if(targetSum == root->val && !root->left && !root->right){
            ans.push_back(cur);
        }else{
            dfs(root->left,  targetSum-root->val, cur);
            dfs(root->right, targetSum-root->val, cur);
        }
    }
};