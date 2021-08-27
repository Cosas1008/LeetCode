/*
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
*/
// First pass, get total
// calculate max ret;
class Solution {
public:
    int maxProduct(TreeNode* root) {
        total = s(root);
        s(root);
        return res % (int)(1e9+7);
    }
    int s(TreeNode* r){
        if(!r) return 0;
        sum = r->val + s(r->right) + s(r->left);
        res = max(res, sum * (total - sum));
        return sum;
    }
private:
    long res = 0;
    long total = 0;
    long sum;
};