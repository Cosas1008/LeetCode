class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        d = 0;
        dfs(root);
        return d;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int ln = dfs(root->left); // height of left node
        int rn = dfs(root->right); // height of right node
        d = max(d, ln+rn);
        return max(ln,rn)+1;
    }
private:
    int d; // diameter
};