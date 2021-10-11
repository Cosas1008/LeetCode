// Inorder Traversal
class Solution{
public:
    int minDiffInBST(TreeNode* root){
        if(root->left) minDiffInBST(root->left);
        if(pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if(root->right) minDiffInBST(root->right);
        return res;
    }
private:
    int res = INT_MAX, pre = -1;
};