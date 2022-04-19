// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
class Solution {
public:
  TreeNode* first, *second, *ptr;
  void recoverTree(TreeNode* root) {
    ptr = new TreeNode(INT_MIN);
    inorder(root);
    swap(first->val, second->val);
  }
  void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    if(first == nullptr && ptr->val > root->val)
      first = ptr;
    if(first && ptr->val > root->val)
      second = root;
    ptr = root;
    inorder(root->right);
  }
};