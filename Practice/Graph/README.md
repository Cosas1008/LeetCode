
### Problem Set
- [x] 130  Surrounded Regions
- [x] 133  Clone Graph
- [x] 200  Number of Islands
- [x] 207  Course Schedule ( cycle detection )
- [x] 210  Course Schedule II
- [x] 286  Walls and Gates
- [x] 310  Minimum Height Trees
- [ ] 317  Shortest Distance from All Buildings ( not so hard, BFS is the key)
- [x] 399  Evaluate Division ( DFS )
- [x] 743  Network Delay Time
- [x] 778  Swim in Rising Water
- [x] 785  Is Graph Bipartite?
- [x] 787  Cheapest Flight Within K Step
- [x] 797  All Path from Source to Target ( DAG, Easy )
- [x] 827  Making A Large Island ( I think this is the easy one with some technique)
- [x] 834  Sum of Distances in Tree
- [x] 847  Shortest Path Visiting All Nodes ( Hard, using DFS )
- [x] 822  Reachable Nodes In Subdivided Graph ( Dijkstra )
- [x] 934  Shortest Bridge ( Connect 2 island, how to paint??)
- [x] 939  Min Area Rectangle
- [ ] 1129 Shortest Path with Alternating Colors
- [ ] 1162 As Far from Land as Possible
- [x] 1192 Critical Connections in a Network (  Tarjan's Bridge-Finding Algorithm (TBFA) )
- [ ] 1254 Number of Closed Islands
- [x] 1267 Count Servers that Communicate
- [ ] 1319 Number of Operations to Make Network Connected
- [ ] 1514 Path with Maximum Probability
- [x] 1631 Path With Minimum Effort (Dijkstra )
- [x] 1761 Minimum Degree of a Connected Trio in a Graph
- [x] 1905 Count Sub Islands (DFS, way to deal with boundary)
- [x] 1976 Number of Ways to Arrive at Destination ( Dijkstra )
- [x] 2096 Valid Arrangement of Pairs
### Basic

1. DFS and BFS    
2. Union Find    
3. Adjacency Matrix   
4. Topology Search

[Youtube](https://www.youtube.com/watch?v=09_LlHjoEiY)

### Algorithms
1. Bellman Ford
2. Dijkstra's
3. Tarjan's Bridge-Finding Algorithm (TBFA)

### Union Find
```
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
```

### 685 Redundent Connection for Directed Graph
![graph](https://discuss.leetcode.com/assets/uploads/files/1507232873325-screen-shot-2017-10-05-at-2.25.34-pm-resized.png)
[Explain](https://leetcode.com/problems/redundant-connection-ii/discuss/108058/one-pass-disjoint-set-solution-with-explain)