/*
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

We can thing of algorithm for circle detection in an undirected graph

Hint : DFS, Tarjan's Bridge-Finding Algorithm (TBFA)
*/
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc.resize(n, 0);
        low.resize(n, 0);
        for(auto connection : connections){
            g[connection[0]].push_back(connection[1]);
            g[connection[1]].push_back(connection[0]);
        }
        dfs(0);
        return ans;
    }
    void dfs(int cur, int pre = -1){
        disc[cur] = low[cur] = time++;
        for(int edge : g[cur]){
            if(disc[edge] == 0){ // not visit yet
                dfs(edge, cur);
                low[cur] = min(low[cur], low[edge]);
            }else if( edge != pre ){ // if visit, then we have to check whether the edge connect to pre
                low[cur] = min(low[cur], disc[edge]);
            }
            // finally, key here is low means the best effect edge find, if the time stemp is larger than disc of current, then it is bridge
            if(low[edge] > disc[cur])
                ans.push_back({cur, edge});
        }
    }
private:
    vector<int> disc, low;
    int time = 1;
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> g;
};