class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // bfs
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool startfromleft = true;
        while(q.size()){
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i < size; ++i){
                TreeNode* node = q.front(); q.pop();
                int idx = (startfromtleft)? i : (size - i - 1);
                row[idx] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            startfromleft = !startfromleft;
            res.push_back(row);
        }
        return res;
    }
};