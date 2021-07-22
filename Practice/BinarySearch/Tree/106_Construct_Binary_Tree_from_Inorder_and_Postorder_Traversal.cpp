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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        pick = size - 1;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return constructTree(postorder, 0, size -1);
    }
    TreeNode* constructTree(vector<int>& postorder, int left, int right){
        if(left>right) return NULL;
        int val = postorder[pick--];
        TreeNode* root=new TreeNode(val);
        root->right = constructTree(postorder,mp[val]+1,right);
        root->left  = constructTree(postorder,left,mp[val]-1);
        return root;
    }
private:
    int pick;
    unordered_map<int,int> mp;
};
// Practice
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int sz = postorder.size();
        for(int i = 0; i < sz; i++){
            mp[inorder[i]] = i;
        }
        pick = sz - 1;
        return helper(postorder, mp, 0, sz - 1);
    }
    TreeNode* helper(vector<int>& postorder, unordered_map<int,int>& mp, int left, int right){
        if(left > right) return NULL;
        int val = postorder[pick--];
        TreeNode* node = new TreeNode(val);
        node->right = helper(postorder, mp, mp[val]+1, right);
        node->left  = helper(postorder, mp, left, mp[val]-1);
        return node;
    }
private:
    int pick;
};