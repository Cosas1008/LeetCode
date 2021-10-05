/*
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int res = INT_MIN, level;
        vector<vector<int>> vlevel;
        helper(root, 0, vlevel);
        for(int i = 0; i < vlevel.size(); i++){
            int total = accumulate(vlevel[i].begin(), vlevel[i].end(), 0);
            if(res < total){
                res = total;
                level = i;
            }
        }
        return level+1;
    }
    void helper(TreeNode* root, int level, vector<vector<int>>& vlevel){
        if(!root) return;
        if(vlevel.size() < level + 1){
            vlevel.push_back({root->val});
        }else{
            vlevel[level].push_back(root->val);
        }
        helper(root->left, level+1, vlevel);
        helper(root->right, level+1, vlevel);
    }
};