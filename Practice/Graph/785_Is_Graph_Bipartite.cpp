/*
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
0 connect to 1,2,3
1 connect to 0, 2 ... etc
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& G) {
        int n = G.size();
        vector<int> colors(n, 0);
        
        for(int i = 0; i < n; ++i){
            if(colors[i] == 0 && !dfs(G, colors, i, 1))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>& G, vector<int>& colors, int i, int color){
        colors[i] = color;
        for(int j = 0; j < G[i].size(); j++){
            int k = G[i][j]; // adjacent node
            if(colors[k] == -color) continue;
            if(colors[k] == color || !dfs(G, colors, k, -color)) return false;
        }
        return true;
    }
};