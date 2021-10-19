// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return rootSum(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int rootSum(TreeNode* root, int targetSum){
        if(!root) return 0;
        return (root->val == targetSum) + rootSum(root->left, targetSum - root->val) + rootSum(root->right, targetSum - root->val);
    }
};