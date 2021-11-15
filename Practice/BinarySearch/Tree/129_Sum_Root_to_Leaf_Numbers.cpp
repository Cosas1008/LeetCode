/*
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int val){
        return root->left == root->right? val * 10 + root->val :
            ((root->left ? dfs(root->left, val * 10 + root->val) : 0) +
             (root->right? dfs(root->right, val * 10 + root->val): 0));
    }
};