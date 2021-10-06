#define PLI pair<long long, int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9+7;
        unordered_map<int, unordered_map<int,long long>> graph;
        for(auto r : roads) graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];
        vector<long long> dist(n, LONG_MAX); // key[node] = dist
        vector<long long> ways(n);
        priority_queue<PLI, vector<PLI>, greater<> > pq;
        pq.emplace(0ll, 0);
        ways[0] = 1;
        while(!pq.empty()){
            auto [move, u] = pq.top();  pq.pop();
            if(move > dist[u]) continue;
            for(auto [v, time] : graph[u]){
                if(dist[v] > move + time){
                    dist[v] = move + time;
                    ways[v] = ways[u];
                    pq.emplace(make_pair(dist[v], v));
                }else if( dist[v] == move + time){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};

#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& r : roads){
            graph[(ll)r[0]].emplace_back(r[1], r[2]);
            graph[(ll)r[1]].emplace_back(r[0], r[2]);
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& G, int n, int src){
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.emplace(0, 0);
        while(minHeap.size()){
            auto [d, u] = minHeap.top(); minHeap.pop();
            if(d > dist[u]) continue; // distance is greater than traversed
            for(auto [v, time] : graph[u]){
                if(dist[v] > d + time){
                    ways[v] = ways[u];
                    dist[v] = d + time;
                    minHeap.emplace(dist[v], v);
                }else if(dist[v] == d + time){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
private:
    int MOD = 1e9+7;
};