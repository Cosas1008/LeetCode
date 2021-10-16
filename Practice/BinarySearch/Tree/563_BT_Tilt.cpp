/*
Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values.
Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1
*/
class Solution {
public:
    int res = 0;
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        postorder(root);
        return res;
    }
    int postorder(TreeNode* root){
        if(!root) return 0;
        int left = postorder(root->left);
        int right = postorder(root->right);
        res += abs(left - right);
        return left + right + root->val;
    }
};