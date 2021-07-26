class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        char *token = strtok(data, ",");
        int level = 1;
        queue<TreeNode*> qu;
        TreeNode* root;
        TreeNode* cur;
        cur = root;
        qu.push(cur);
        while(token != NULL){
            int sz = level * level; level++;
            for(int i = 0; i < sz; i++){
                int val = token.stoi();
                TreeNode* newNode = new TreeNode(val);
                cur = newNode;
                token
            }
        }
        return root;
    }
};
