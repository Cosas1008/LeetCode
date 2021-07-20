// Hash table to store
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(st.find(k - root->val) != st.end()) return true;
        st.insert(root->val);
        return findTarget(root->right, k) || findTarget(root->left, k);
    }
private:
    set<int> st;
};
// Inorder Traversal
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        vector<int> vt;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            vt.push_back(root->val);
            root = root->right;
        }
        for(int i = 0, j = vt.size()-1; i < j;){
            if(vt[i] + vt[j] == k) return true;
            if(vt[i] + vt[j] < k) i++;
            else j--;
        }
        return false;
    }
};