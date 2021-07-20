class Solution {
public:
    vector<int> findMode(TreeNode* root){
        inorder(root, false);
        // cout << "maxCount " << maxCount << endl;
        inorder(root, true);
        return ans;
    }
    void inorder(TreeNode* root, bool getlist){
        if(!root) return;
        int curCount = 1;
        TreeNode* prev = NULL;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }

            root = st.top(); st.pop();

            if(prev && prev->val == root->val){
                curCount++;
            }else{
                curCount = 1;
            }

            if(!getlist) maxCount = max(maxCount, curCount);
            else if(curCount == maxCount) ans.push_back(root->val);

            prev = root;
            root = root->right;
        }
    }
private:
    vector<int> ans;
    int maxCount;
};