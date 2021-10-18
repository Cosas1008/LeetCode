// Two nodes of a binary tree are cousins if they have the same depth with different parents.
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q; // [node, parent]
        q.emplace(root,nullptr);
        while(q.size()){
            TreeNode* xp = nullptr, *yp = nullptr;
            int n = q.size(); // same level
            for(int i = 0; i < n; ++i){
                auto[t, p] = q.front(); q.pop();
                if(t->val == x) xp = p;
                else if(t->val == y) yp = p;
                if(t->left) q.emplace(t->left, t);
                if(t->right) q.emplace(t->right, t);
            }
            if(xp || yp) return xp && yp && xp != yp;
        }
        return false;
    }
};