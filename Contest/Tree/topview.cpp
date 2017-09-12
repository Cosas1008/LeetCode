/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void topView(node * root) {
    unordered_map<int,int> m; // store the key map to value
    queue<pair<node*,int>> q;
    
    if(!root){
        return;
    }
    q.push(make_pair(root, 0));
    
    
    while(!q.empty())
    {
        pair<node*,int> p = q.front();
        node* newNode = p.first;
        int ht = p.second;
        
        if
        
        if(root->left){
            q.push(make_pair(root->left,ht - 1));
        }
        if(root->right){
            q.push(make_pair(root->right,ht + 1));
        }
        q.pop(); // remove the value from front
    }
    
  
}
