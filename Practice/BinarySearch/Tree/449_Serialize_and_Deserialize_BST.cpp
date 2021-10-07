class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }
    string encode(TreeNode* root){
        if(!root) return "";
        return to_string(root->val) + '-' + encode(root->left) + encode(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string ivalue;
        TreeNode* root = NULL;
        while(getline(ss, ivalue, '-')){
            root = decode(root, stoi(ivalue));
        }
        return root;
    }
    TreeNode* decode(TreeNode* root, int value){
        if(!root){
            TreeNode* tmp  = new TreeNode(value);
            return tmp;
        }
        if(root->val > value)
            root->left = decode(root->left, value);
        else
            root->right = decode(root->right, value);
        return root;
    }
};