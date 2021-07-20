/*
Given two binary search trees, return True if and only if there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.
Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.
*/
// Idea traversal root1 first with populate bit on, and then turn dfs(root2, target, visited, false)
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> visited;
        dfs(root1, target, visited, true);
        return dfs(root2, target, visited, false);
    }
    bool dfs(TreeNode* root, int target, unordered_set<int>& visited, bool populate) {
        if (root == nullptr)    return false;
        if (populate) {
            visited.insert(root->val);
        } else {
            if (visited.count(target - root->val))  return true;
        }
        return dfs(root->left, target, visited, populate) || dfs(root->right, target, visited, populate);
    }
}