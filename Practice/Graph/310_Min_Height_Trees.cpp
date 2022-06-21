/*
Given a tree of n nodes labelled from 0 to n - 1,
and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree,
you can choose any node of the tree as the root.
When you select a node x as the root, the result tree has height h.
Among all possible rooted trees, those with minimum height (i.e. min(h)) are called minimum height trees (MHTs).

Hint: similar to 207 Course Schedule, using topology
*/
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return {0};
        vector<int> deg(n, 0), rank;
        vector<vector<int>> adj(n, vector<int>());
        for (auto edge : edges)
        {
            int a = edge[0], b = edge[1];
            deg[a]++;
            deg[b]++;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (deg[i] == 1)
                q.push(i);

        while (!q.empty())
        {
            int level = q.size();
            rank.clear();
            for (int i = 0; i < level; ++i)
            {
                int t = q.front();
                q.pop();
                rank.push_back(t);
                deg[t]--;
                for (int j = 0; j < adj[t].size(); ++j)
                {
                    if (--deg[adj[t][j]] == 1)
                        q.push(adj[t][j]);
                }
            }
        }
        return rank;
    }
};