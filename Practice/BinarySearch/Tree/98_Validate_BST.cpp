/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // WRONG!! Not considering previous traversal value, use inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root->left && root->val <= root->left->val) return false;
        if(root->right && root->val >= root->right->val) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
// Inorder Traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        while(root || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
// Recurssive (cool)
bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}