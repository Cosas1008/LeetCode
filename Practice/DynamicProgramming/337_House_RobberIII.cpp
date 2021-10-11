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
// It will automatically contact the police if two directly-linked houses were broken into on the same night.
// TLE, Time Complexity O(4^n)
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        return max(helper(root->right, false) + helper(root->left, false), root->val + helper(root->right) + helper(root->left));
    }
    int helper(TreeNode* rt, bool chose = true){
        if(!rt) return 0;
        if(chose){
            return helper(rt->right, false) + helper(rt->left, false); // skip current
        }else{
            return max(helper(rt->right, false) + helper(rt->left, false), rt->val + helper(rt->right) + helper(rt->left));
        }
    }
};

// Clever Solution
class Solution {
public:
    int rob(TreeNode* root) {
        int left, right;
        return tryRob(root, left, right);
    }
    int tryRob(TreeNode* rt, int& left, int & right){
        if(!rt) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        left = tryRob(rt->left, ll, lr);
        right = tryRob(rt->right, rl, rr);
        return max(rt->val + ll + lr + rl + rr, left + right);
    }
};