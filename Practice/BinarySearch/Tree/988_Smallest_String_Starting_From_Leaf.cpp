/*
You are given the root of a binary tree where each node has a value in the range [0, 25]
 representing the letters 'a' to 'z'.
*/
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string ret = "|"; // '|' 's position is later than a-z
        dfs(root, ret, "");
        return ret;
    }
    void dfs(TreeNode* root, string& ret, string cur){
        if(!root) return;
        char c = 'a' + root->val;
        cur  = c + cur;
        // cout << cur << endl;
        if(!root->left && !root->right){
            if(cur < ret)
                ret = cur;
        }else{
            dfs(root->left, ret, cur);
            dfs(root->right, ret, cur);
        }
    }
};