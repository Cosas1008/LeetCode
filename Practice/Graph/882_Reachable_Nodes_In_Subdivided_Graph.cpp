/*
In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.
Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
*/

class Solution {
public:
    // Dijkstra's
    // Treating the original graph as a weighted, undirected graph, we can use Dijkstra's algorithm to find all reachable nodes in the original graph.
    // Time Complexity O(E log E)
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int,int>> e;
        for(auto v : edges) e[v[0]][v[1]] = e[v[1]][v[0]] = v[2];
        priority_queue<pair<int,int>> pq;
        pq.push({M, 0 });
        unordered_map<int,int> seen;
        while(!pq.empty()){
            int moves = pq.top().first, i = pq.top().second;
            pq.pop();
            if(!seen.count(i)){
                seen[i] = moves;
                for(auto j : e[i]){
                    int move2 = moves - j.second - 1;
                    if(!seen.count(j.first) && move2 >= 0)
                        pq.push({move2, j.first});
                }
            }
        }
        int ans = seen.size();
        for(auto v : edges){
            int a = seen.find(v[0]) == seen.end()? 0 : seen[v[0]];
            int b = seen.find(v[1]) == seen.end()? 0 : seen[v[1]];
            ans += min(a + b, v[2]);
        }
        return ans;
    }
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> dist(N, INT_MAX);
        unordered_map<int, unordered_map<int, int>> g;
        for(auto& e:edges)
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){ return a.second > b.second; };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto u = pq.top().first; pq.pop();
            if( dist[u] >= M ) break;
            for(auto n_w: g[u]){
                int v = n_w.first, w = n_w.second;
                if( dist[u] + w < dist[v]){
                    dist[v] = w + dist[u];
                    pq.push({v, dist[v]});
                }
            }
        }
        
        
        int res = 0;
        for(int i = 0; i < N; i++) if(dist[i] <= M) res++;
        /** the smart part **/
        for(auto& e: edges){
            //couting the reachable nodes lying on edge e from node e[0] 
            int a = dist[e[0]] >= M ? 0: min(M-dist[e[0]], e[2]);
            //couting the reachable nodes lying on edge e from node e[1] 
            int b = dist[e[1]] >= M ? 0: min(M-dist[e[1]], e[2]);
            res += min(a + b, e[2]);
        }
        /******************/
        return res;
        
    }
};