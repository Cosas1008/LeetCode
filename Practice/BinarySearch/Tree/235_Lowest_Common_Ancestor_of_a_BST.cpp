/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val, qval = q->val;
        if(pval < qval) return lowestCommonAncestor(root, q, p);
        if(root->val > pval){ // case1 root->val > p -> left
            return lowestCommonAncestor(root->left, p, q);
        } else if(root->val < qval){ // case2 root->val < p and root->val < q ->right
            return lowestCommonAncestor(root->right, p, q);
        } else {  // case3 root->val < p and root->val > q -> hit
            return root;
        }
    }
};