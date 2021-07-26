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
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 */

// Recurssive
class Solution {
public:
    TreeNode* clone(TreeNode *root){
        if(root == NULL) return NULL;
        TreeNode* new_root = new TreeNode(root->val);
        new_root->left = clone(root->left);
        new_root->right = clone(root->right);
        return new_root;
    }

    vector<TreeNode*> generateTrees(int n){
        vector<TreeNode*> result(1, nullptr);
        for(int i = 1; i <= n; i++){
            vector<TreeNode*> tmp;
            for(int j = 0; j < result.size(); j++){
                TreeNode* root = result[j];
                TreeNode* new_root = new TreeNode(i);
                TreeNode* target = clone(root);
                new_root->left = target;
                tmp.push_back(new_root);

                if(root != nullptr){
                    TreeNode* tmpold = root;
                    while(tmpold->right != nullptr){
                        TreeNode* new_right = new TreeNode(i);
                        TreeNode* old_right = tmpold->right;
                        tmpold->right       = new_right;
                        new_right->left     = old_right;
                        TreeNode* target  = clone(root);
                        tmp.push_back(target);
                        tmpold->right       = old_right;
                        tmpold              = tmpold->right;
                    }
                    tmpold->right = new TreeNode(i);
                    TreeNode* target = clone(root);
                    tmp.push_back(target);
                    tmpold->right = nullptr;
                }
            }
            result = tmp;
        }
        return result;
    }
};

// Output only number of generated Trees
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = 0;
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n]; // Catalan numbers
    }
};