/*
Example 2:

Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
*/
// Method 1: DFS (larger Time complexity)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for(auto& edge : edges){
            int s = edge[0];
            int d = edge[1];
            unordered_set<int> visited;
            if(hasPath(s, d, visited, graph))
                return edge;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        return {}; // no redundent edge
    }
    bool hasPath(int s, int d, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph){
        if(s == d) return true;
        visited.insert(s);
        if(!graph.count(s) || !graph.count(d)) return false;
        for(int a : graph[s]){
            if(visited.count(a)) continue;
            if(hasPath(a, d, visited, graph)) return true;
        }
        return false;
    }
};
// Method 2: Union Find
class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);        
        parents_ = vector<int>(n + 1, 0);                
        
        for (int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }
    
    // Merge sets that contains u and v.
    // Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        
        // Meger low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu])
            parents_[pu] = pv;           
        else if (ranks_[pu] > ranks_[pv])
            parents_[pv] = pu;
        else {
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        
        return true;
    }
    
    // Get the root of u.
    int Find(int u) {        
        // Compress the path during traversal
        if (u != parents_[u])
            parents_[u] = Find(parents_[u]);        
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet uf(edges.size());
        for(auto edge : edges){
            if(uf.Find(edge[0]) == uf.Find(edge[1])) return edge;
            uf.Union(edge[0], edge[1]);
        }
        return {}; // not find
    }
};