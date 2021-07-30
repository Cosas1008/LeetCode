/*
times[i] = (ui, vi, wi), where 
    ui is the source node, 
    vi is the target node, 
    and wi is the time it takes for a signal to travel from source to target.
*/

typedef pair<int,int> pii;
class Solution {
public:
    // Bellman Ford
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        for(int i = 0; i < n; i++){
            for(vector<int>& path : times){
                int u = path[0], v = path[1], w = path[2];
                if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i < dist.size(); i++)
            maxTime = max(maxTime, dist[i]);
        return maxTime == INT_MAX? -1 : maxTime;
    }
    // Dijkstra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> graph[n+1];
        for(vector<int>& time : times){
            graph[t[0]].emplace_back(t[1], t[2]);
        }
        const int inf = 1e9;
        vector<int> dist(n+1, inf);
        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // smallest weight
        pq.emplace(0, k);
        int v, u, w;
        while(!pq.empty()){
            pii p = pq.top(); pq.pop();
            u = p.second; // destination
            for(auto& to : graph[u]){
                v = to.first; w = to.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == inf? -1 : ans;
    }
};