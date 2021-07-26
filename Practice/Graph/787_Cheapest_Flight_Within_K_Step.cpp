// Time O(|V|*|E|) V iteration with |E| relaxations for each iter
typedef tuple<int,int,int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // bellman ford algo
        vector<int> pre(n, 1e8);
        pre[src] = 0;
        for(int k = 0; k <= K; k++){
            vector<int> P(pre);
            for(auto flight : flights){
                P[flight[1]] = min(P[flight[1]], pre[flight[0]] + flight[2]);
            }
            pre = P;
        }
        
        return pre[dst] == 1e8? -1 : pre[dst];
    }
    // Dijkstra (TLE)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>vp(n);
        for(const auto &f : flights)
            vp[f[0]].emplace_back(f[1],f[2]);
        priority_queue<ti,vector<ti>,greater<ti>>pq;
        pq.emplace(0,src,K+1);
        while(!pq.empty()){
            auto [cost, u, stop] = pq.top(); pq.pop();
            if(u == dst) return cost;
            if(!stop) continue;
            for(auto to : vp[u]){
                auto [v, w] = to;
                pq.emplace(cost+w, v, stop-1);
            }
        }
        return -1;
    }
    // Alternative 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,unordered_map<int,int>> mp;
        for(const vector<int>& flight : flights)   mp[flight[0]][flight[1]] = flight[2];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        minheap.push({0,src,K+1});
        while(!minheap.empty()){
            vector<int> top = minheap.top();
            minheap.pop();
            int price = top[0];
            int city = top[1];
            int stops = top[2];
            if (city == dst) return price;
            if(stops>0) for(auto &t: mp[city] ) minheap.push({price+t.second, t.first, stops-1});
            }
        return -1;   
    }
};