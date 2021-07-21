// BFS right-to-left, return the last traversed node
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            root = qu.front(); qu.pop();
            if(root->right){
                qu.push(root->right);
            }
            if(root->left) qu.push(root->left);
        }
        return root->val;
    }
};