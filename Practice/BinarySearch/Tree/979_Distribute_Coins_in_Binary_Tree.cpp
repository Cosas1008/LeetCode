/*
Return the minimum number of moves required to make every node have exactly one coin.
*/
// Optimize 2
class Solution {
public:
    int move = 0;
    int distributeCoins(TreeNode* root) {
      traverse(root);
      return move;
    }
    int traverse(TreeNode* root){
      if(!root) return 0;
      int left = traverse(root->left), right = traverse(root->right);
      move += abs(left) + abs(right);
      return root->val + left + right - 1;
    }
};
// Optimize 1
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        traverse(root, moves);
        return moves;
    }
    int traverse(TreeNode* t, int& moves){
        if(t == nullptr) return 0;
        int left = traverse(t->left, moves), right = traverse(t->right, moves);
        moves += abs(left) + abs(right);
        return t->val + left + right - 1;
    }
};

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
private:
    int res = 0;
};