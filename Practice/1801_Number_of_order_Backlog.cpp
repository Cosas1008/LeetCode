#define BUY 0
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>> buy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        int mod = 1e9+7;
        for(auto order : orders){
            int price = order[0], cnt = order[1], type = order[2];
            if(type == BUY){
                while(sell.size() && sell.top().first <= price && cnt){
                    if(sell.top().second <= cnt){
                        cnt -= sell.top().second;
                        sell.pop();
                    }else{
                        auto cur = sell.top();
                        cur.second  -= cnt;
                        cnt = 0;
                        sell.pop(); sell.push(cur);
                    }
                }
                if(cnt) buy.emplace(price, cnt);
            }else{
                while(buy.size() && buy.top().first >= price && cnt){
                    if(buy.top().second <= cnt){
                        cnt -= buy.top().second;
                        buy.pop();
                    }else{
                        auto cur = buy.top();
                        cur.second -= cnt;
                        cnt = 0;
                        buy.pop(); buy.push(cur);
                    }
                }
                if(cnt) sell.emplace(price, cnt);
            }
        }
        long long ans = 0;
        while(!buy.empty()){
            ans += buy.top().second;
            buy.pop();
        }
        while(!sell.empty()){
            ans += sell.top().second;
            sell.pop();
        }
        return ans % mod;
    }
};