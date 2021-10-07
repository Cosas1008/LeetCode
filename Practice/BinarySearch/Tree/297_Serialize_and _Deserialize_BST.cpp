class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "|";
        return to_string(root->val) + '|' + serialize(root->left) + serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    TreeNode* decode(stringstream& ss){
        string token;
        getline(ss, token, '|');
        if(token == ""){
            return NULL;
        }
        TreeNode *t = new TreeNode(stoi(token));
        t->left = decode(ss);
        t->right = decode(ss);
        return t;    
    }
};