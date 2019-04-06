/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
/*
//Sep 13rd, 2017

void topView(node * root) {
    set<pair<int,int>> s; // store the key map to value
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
        
        pair<int,int> insertpair = make_pair(ht,newNode->data);
        s.insert(insertpair);
        
        if(root->left){
            q.push(make_pair(root->left,ht - 1));
        }
        if(root->right){
            q.push(make_pair(root->right,ht + 1));
        }
        q.pop(); // remove the value from front
    }
    
    set<pair<int,int>>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        pair<int,int> m = *it;
        cout << m.second << " ";
    }
    cout << endl;
}

*/
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
// Sep 14th, 2017

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

typedef map<int,int> maps;
void topView(node * root) {
    maps m; // store the key map to value
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
        
        pair<int,int> insertpair = make_pair(ht,newNode->data);
        m.insert(insertpair);
        
        if(root->left){
            q.push(make_pair(root->left,ht - 1));
            }
        if(root->right){
            q.push(make_pair(root->right,ht + 1));
        }
        q.pop(); // remove the value from front
    }
    maps::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << it->second << " ";
    }
    cout << endl;
}
int main()
{
    /* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
                 
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    root->left->right->right=newNode(5);
    root->left->right->right->right=newNode(6);
     
    topView(root);
    return 0;
}