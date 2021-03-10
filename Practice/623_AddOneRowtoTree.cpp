class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 0 || d == 1) {
            TreeNode* newNode = new TreeNode(v);
            ((d == 1)? newNode->left : newNode->right) = root;
            return newNode;
        }
        if(root && d > 1){
            root->left = addOneRow(root->left, v, (d == 2)? 1: d-1);
            root->right = addOneRow(root->right, v, (d == 2)? 0: d-1);
        }
        return root;
    }
};