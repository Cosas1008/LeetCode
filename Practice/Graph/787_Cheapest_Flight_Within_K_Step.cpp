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
};