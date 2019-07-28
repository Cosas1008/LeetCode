class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(root, s);
        s.erase(s.begin());
        return s.empty() ? -1 : *s.begin();
    }

    void dfs(TreeNode * p, set<int> & s) {
        if ( p ) {
            s.insert(p->val);
            dfs(p->left, s);
            dfs(p->right, s);
        }
    }
};

// Runtime: 3 ms