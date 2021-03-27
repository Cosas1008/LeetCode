class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > sell; // min heap
        priority_queue<vector<int>> buy; // max heap
        for(vector<int> order : orders){
            int p = order[0], n = order[1], t = order[2];
            if(t == 0){ // buy order
                
                while(sell.size() && sell.top()[0] <= p && n){
                    vector<int> cur = sell.top();
                    if(cur[1] <= n){
                        n -= cur[1];
                        sell.pop();
                    }else{
                        cur[1] -= n;
                        n = 0;
                        sell.pop();
                        sell.push(cur);
                    }
                }
                if(n) buy.push({p,n,t});
                
            }else{ // sell order
                
                while(buy.size() && buy.top()[0] >= p && n){
                    vector<int> cur = buy.top();
                    if(cur[1] <= n){
                        n -= cur[1];
                        buy.pop();
                    }else{
                        cur[1] -= n;
                        n = 0;
                        buy.pop();
                        buy.push(cur);
                    }
                }
                if(n) sell.push({p,n,t});
            }
        }
        long long res = 0;
        while(!buy.empty()){
            res += buy.top()[1];
            buy.pop();
        }
        while(!sell.empty()){
            res += sell.top()[1];
            sell.pop();
        }
        return res % 1000000007;
    }
};

/*
This is better
https://leetcode.com/problems/number-of-orders-in-the-backlog/discuss/1122438/C%2B%2B-2-Heaps

*/