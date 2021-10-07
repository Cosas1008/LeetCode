class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        string ans = to_string(root->val);
        if(root->left)
            ans += "(" + tree2str(root->left) + ")";
        else if(root->right) // need to add this for null left + right
            ans += "()";
        if(root->right)
            ans += "(" + tree2str(root->right) + ")";
        return ans;
    }
};