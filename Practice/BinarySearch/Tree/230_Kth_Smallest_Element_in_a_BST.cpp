class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
        return -1; // not find
    }
};
// Alternative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if (k <= cnt) {
            return kthSmallest(root->left, k);
        } else if (k > cnt + 1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        return root->val;
    }
    int count(TreeNode* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
};

// Need to read the follow up question with same "count" concept
class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        return find(root, k);
    }
    int find(TreeNode* root, int k){
        if(root){
            int x = find(root->left, k);
            return !k? x : !--k? root->val : find(root->right, k);
        }
    }
};