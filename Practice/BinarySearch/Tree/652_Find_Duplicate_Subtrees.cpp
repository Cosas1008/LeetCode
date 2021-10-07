/*
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
*/
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicate;
        encode(root);
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->second.size() > 1){
                duplicate.push_back(it->second[0]);
            }
        }
        return duplicate;
    }
    string encode(TreeNode* root){
        if(!root) return "";
        string serialize = "(" + encode(root->left) + to_string(root->val) + encode(root->right) + ")";
        mp[serialize].push_back(root); // record string
        return serialize;
    }
private:
    unordered_map<string, vector<TreeNode*>> mp;
};