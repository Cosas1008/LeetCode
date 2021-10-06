# Union Find
union and find functions have worst case O(N), amortize O(1)
The whole union-find solution with path compression, has O(N) Time, O(N) Space
Ref: [Count-the-Number-of-Islands-O(N)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N))

## TODO List

- [x] 261  Graph Valid Tree
- [ ] 305  Number of Island II
- [x] 547  Number of Provinces
- [x] 684  Redundent Connection
- [x] 685  Redundent Connection II (directed graph)
- [x] 721  Accounts Merge
- [x] 947  Most Stones Removed with Same Row or Column
- [ ] 928 Minimize Malware Spread II

### 947
Problem:
we can remove a stone if and only if,
there is another stone in the same column OR row. We try to remove as many as stones as possible.

Solve 547 too!
