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
    // Alternative
    int ans = 0;
    int pathSum(TreeNode* root, int sum){
        if(root){
            dfs(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;
    }
    void dfs(TreeNode* root, int sum){
        if(!root) return;
        if(root->val == sum) ans++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};