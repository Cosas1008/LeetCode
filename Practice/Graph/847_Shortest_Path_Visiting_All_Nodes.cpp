/*
An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
*/
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        const int allOne = (1 << n) - 1;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1<<n, false));
        for(int i = 0; i < graph.size(); ++i)
            q.emplace(i, 1<<i); // node and state
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto p = q.front(); q.pop();
                int n = p.first; // node
                int s = p.second; // state
                if(s == allOne) return steps;
                if(visited[n][s]) continue;
                visited[n][s] = true;
                for(int next : graph[n])
                    q.emplace(next, (s | 1 << next));
            }
            ++steps;
        }
        return -1;
    }
};