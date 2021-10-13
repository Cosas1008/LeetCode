class Solution {
public:
    int i;
    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
        if(i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val); // The left recursion will take the elements smaller than node.val
        root->right = bstFromPreorder(A, bound);
        return root;
    }
};