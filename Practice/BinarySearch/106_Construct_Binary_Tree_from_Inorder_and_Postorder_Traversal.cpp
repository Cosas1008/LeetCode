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

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return helper(preorder, mp, 0, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& pre, unordered_map<int,int>& mp, int pick, int left, int right){
        int val = pre[pick];
        int mid = mp[val];
        TreeNode* root = new TreeNode(val);
        if(mid > left){
            root->left = helper(pre, mp, pick+1, left, mid-1);
        }
        if(mid < right){
            root->right = helper(pre, mp, pick+mid-left+1, mid+1, right);
        }
        return root;
    }
};