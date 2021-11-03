
struct Node {
    Node *right, *down;
    int val;
    Node(Node *right, Node*down, int val): right(right), down(down), val(val) {}
};

class Skiplist {
public:
    Skiplist() {
        head = new Node(NULL, NULL, 0);
    }
    
    bool search(int target) {
        Node* p = head;
        while(p){
            while(p->right && p->right->val < target) p = p->right;
            if(!p->right || p->right->val > target) p = p->down;
            else return true;
        }
        return false;
    }
    
    void add(int num) {
        Node* p = head;
        insertVec.clear();
        while(p){
            while(p->right && p->right->val < num) p = p->right;
            insertVec.push_back(p);
            p = p->down;
        }
        Node* downNode = NULL;
        bool insertUp = true;
        while(insertUp && insertVec.size()){
            Node* ins = insertVec.back();
            insertVec.pop_back();
            
            ins->right = new Node(ins->right, downNode, num);
            downNode = ins->right;
            insertUp = (rand() & 1) == 0;
        }
        if(insertUp){
            head = new Node(new Node(NULL, downNode, num), head, 0);
        }
    }
    
    bool erase(int num) {
        Node *p = head;
        bool seen = false;
        while(p) {
            while(p->right and p->right->val < num) p = p->right;
            if(!p->right or p->right->val > num) p = p->down;
            else {
                seen = true;
                p->right = p->right->right;
                p = p->down;
            }
        }
        return seen;
    }
private:
    Node* head;
    vector<Node*> insertVec;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */