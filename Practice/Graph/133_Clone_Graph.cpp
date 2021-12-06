/*
The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
*/

class Node {
    public int val;
    public List<Node> neighbors;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> m;
        Node* copy = new Node(node->val);
        m[node] = copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* ptr = q.front(); q.pop();
            for(Node* n : ptr->neighbors){
                if(m.find(n) == m.end()){
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[ptr]->neighbors.push_back(m[n]);
            }
        }
        return copy;
    }
};