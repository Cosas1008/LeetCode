/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        collect(root);
        vector<int> values(numbers.begin(), numbers.end());
        sort(values.begin(), values.end());
        return values[k-1];
    }
    
private:
    set<int> numbers;
    //depth-first search
    void collect(TreeNode* leaf)
    {
        numbers.insert(leaf->val);
        if(leaf->left){collect(leaf->left);};
        if(leaf->right){collect(leaf->right);};
    }
};