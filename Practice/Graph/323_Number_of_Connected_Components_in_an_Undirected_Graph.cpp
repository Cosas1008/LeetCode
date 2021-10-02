/*
iven n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
*/
class Solution{
public:
    // union find
    int countComponents(int n, vector<vector<int>> edges){
        vector<int> root(n);
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
        int cnt = n;
        for(auto e : edges){
            int r1 = getRoot(root, e[0]);
            int r2 = getRoot(root, e[1]);
            if(r1 != r2){
                root[r1] = r2;
                cnt--;
            }
        }
        return cnt;
    }
private:
    int getRoot(vector<int>& root, int i){
        while(root[i] != i){
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
    // dfs
    int countComponents(int n, vector<vector<int>> edges){
        int res = 0;
        vector<vector<int> > g(n); // graph
        vector<bool> v(n, false); // visit
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ++res;
                dfs(g, v, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int> > &g, vector<bool> &v, int i) {
        if (v[i]) return;
        v[i] = true;
        for (int j = 0; j < g[i].size(); ++j) {
            dfs(g, v, g[i][j]);
        }
    }
};