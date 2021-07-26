### Basic

1. DFS and BFS    
2. Union Find    

[Youtube](https://www.youtube.com/watch?v=09_LlHjoEiY)

### Algorithms
1. Bellman Ford
2. Dijkstra's

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

### Problem Set
- [x] 684 Redundent Connection
- [x] 685 Redundent Connection II (directed graph)
- [x] 778 Swim in Rising Water
- [x] 787 Cheapest Flight Within K Step