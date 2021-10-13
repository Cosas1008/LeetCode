class Solution {
public:
    // DFS
    int longestZigZag(TreeNode* root) {
        int res = 0;
        dfs(root, false, res, 0);
        dfs(root, true , res, 0);
        return res;
    }
    void dfs(TreeNode* root, bool goleft, int& res, int cnt){
        if(!root) return;
        res = max(cnt, res);
        if(goleft){
            dfs(root->left, false, res, cnt+1);
            dfs(root->right, true, res, 1);
        }else{
            dfs(root->right, true, res, cnt+1);
            dfs(root->left, false, res, 1);
        }
    }
};