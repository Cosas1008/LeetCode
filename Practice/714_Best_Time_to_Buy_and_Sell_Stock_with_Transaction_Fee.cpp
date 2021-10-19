/*
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/
class Solution {
public:
    // DP, TLE
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); // min possible number of transactions is n/2 times
        vector<int> dp(n/2 + 1, 0);
        vector<int> minP(n/2 + 1, prices[0]);
        for(int i = 1; i < n; ++i){
            for(int k = 1; k <= n/2; ++k){
                minP[k] = min(minP[k], prices[i] - dp[k-1]);
                dp[k]   = max(dp[k], prices[i] - minP[k] - fee);
            }
        }
        int ret = dp[0];
        for(int i = 1; i <= n/2; ++i)
            ret = max(ret, dp[i]);
        return ret;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0, s1 = INT_MIN;
        for(int p : prices){
            int tmp = s0;
            s0 = max(s0, s1+p);      // Profit selling stock
            s1 = max(s1, tmp-p-fee); // Profit buying  stock
        }
        return s0;
    }
};