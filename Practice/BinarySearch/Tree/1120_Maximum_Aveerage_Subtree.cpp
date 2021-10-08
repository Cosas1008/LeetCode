/*
Input: [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
*/
class Solution{
public:
    int maximumAverageSubtree(TreeNode* root){
        // post order traversal
        int cnt = 0, total = 0;
        dfs(root, cnt, total);
        return res;
    }
    void dfs(TreeNode* root, int& cnt, int& total){
        if(!root) return;
        
        int cnt1, cnt2, total1, total2;
        cnt1 = cnt2 = total1 = total2 = 0;

        dfs(root->left, cnt1, total1);
        dfs(root->right, cnt2, total2);
        cnt = cnt1 + cnt2 + 1;
        tatal = total1 + total2 + root->val;
        res = max(total/cnt, res);
    }
private:
    int res = 0;
};