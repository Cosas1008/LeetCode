/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1 and return them in any order.

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> res;
        dfs(graph, 0, target, {0}, res);
        return res;
    }
    void dfs(vector<vector<int>>& G, int src, int dst, vector<int> path, vector<vector<int>>& res){
        if(src == dst){
            res.emplace_back(path);
            return;
        }
        for(auto node : G[src]){
            path.emplace_back(node);
            dfs(G, node, dst, path, res);
            path.pop_back();
        }
    }
};