/*
A connected trio is a set of three nodes where there is an edge between every pair of them.
The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.
*/
class Solution {
public:
    // Adjacency List Worst Runtime
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> al(n + 1);
        vector<int> cnt(n + 1);
        int res = INT_MAX;
        for (auto &e: edges) {
            al[min(e[0], e[1])].insert(max(e[0], e[1]));
            ++cnt[e[0]];
            ++cnt[e[1]];
        }
        for (auto t1 = 1; t1 <= n; ++t1)
            for (auto it2 = begin(al[t1]); it2 != end(al[t1]); ++it2)
                for (auto it3 = next(it2); it3 != end(al[t1]); ++it3)
                    if (al[*it2].count(*it3))
                        res = min(res, cnt[t1] + cnt[*it2] + cnt[*it3] - 6);
        return res == INT_MAX ? -1 : res;
    }
    // Adjacency Matrix
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> am(n+1, vector<int>(n+1));
        vector<int> cnt(n + 1);
        int res = INT_MAX;
        for (auto &e: edges) {
            al[min(e[0], e[1])][max(e[0], e[1])] = 1;
            ++cnt[e[0]];
            ++cnt[e[1]];
        }
        for (int t1 = 1; t1 <= n; ++t1)
            for (int t2 = t1+1; t2 <= n; t2++)
                if(am[t1][t2])
                    for (int t3 = t2+1; t3 <= n; t3++)
                        if (am[t1][t3] && am[t2][t3])
                            res = min(res, cnt[t1] + cnt[t2] + cnt[t3] - 6);
        return res == INT_MAX ? -1 : res;
    }
};