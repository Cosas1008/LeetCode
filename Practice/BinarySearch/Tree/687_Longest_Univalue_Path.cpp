class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left); // length of single direction Longest-Univalue-Path start from left-child
        int right = dfs(root->right); // length of single direction Longest-Univalue-Path start from right-child
        int uniLeft = 0, uniRight = 0;
        if(root->left && root->left->val == root->val) // start from parent go left
            uniLeft += left + 1;
        if(root->right && root->right->val == root->val) // start from parent go right
            uniRight += right + 1;
        
        ans = max(ans, uniLeft + uniRight);
        return max(uniLeft, uniRight);
    }
    int ans = 0;
};