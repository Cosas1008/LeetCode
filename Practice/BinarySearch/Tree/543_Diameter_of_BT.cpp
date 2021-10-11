class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dfs(root, d);
        return d;
    }
    int dfs(TreeNode* root, int& d){
        if(!root) return 0;
        int ln = dfs(root->left, d); // height of left node
        int rn = dfs(root->right,d); // height of right node
        d = max(d, ln+rn);
        return max(ln,rn)+1;
    }
};