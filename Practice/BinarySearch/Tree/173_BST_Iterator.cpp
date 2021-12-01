/*
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]
*/
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        find_left(root);
    }
    
    int next() {
        TreeNode* top = st.top(); st.pop();
        if(top->right)
            find_left(top->right);
        return top->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
    void find_left(TreeNode* root){
        TreeNode* p = root;
        while(p){
            st.push(p);
            p = p->left;
        }
    }
};