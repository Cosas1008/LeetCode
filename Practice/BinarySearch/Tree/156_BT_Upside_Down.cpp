class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(!root || !root->left) return root;
        TreeNode* ln = root->left, *rn = root->right;
        TreeNode* res = upsideDownBinaryTree(l);
        ln->left = rn;
        ln->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};