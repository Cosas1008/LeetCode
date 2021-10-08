/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/
class Solution{
public:
    bool validTree(int n, vector<vector<int>> edges){
        vector<int> nodes(n, -1);
        for(auto e : edges){
            int x = find(nodes, e[0]);
            int y = find(nodes, e[1]);
            if(x == y)
                return false;
            nums[y] = x; // key
        }
        return edges.size() == n-1; // all connected
    }
    int find(vector<int>& nodes, int i){
        if(nodes[i] == -1) return i;
        return find(nodes, nodes[i]);
    }
}