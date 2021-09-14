/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
*/
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for(auto e: edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        postOrder(0, -1);
        preOrder(0, -1);
        return res;
    }
    void postOrder(int root, int pre){
        for(auto i : tree[root]){
            if(i == pre) continue;
            postOrder(i, root);
            count[root] += count[i];
            res[root]   += count[i] + res[i];
        }
    }
    void preOrder(int root, int pre){
        for(auto i : tree[root]){
            if(i == pre) continue;
            // When we move our root from parent to its child i, count[i] points get 1 closer to root, n - count[i] nodes get 1 futhur to root.
            res[i] = res[root] - count[i] + count.size() - count[i];
            preOrder(i, root);
        }
    }
private:
    vector<unordered_set<int>> tree;
    vector<int> count, res;
};