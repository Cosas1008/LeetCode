/*

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> s0(n, 0), s1(n, 0), s2(n, 0);
        s0[0] = 0;  // cooldown
        s1[0] = -prices[0]; // buy
        s2[0] = INT_MIN; // profit by sell
        for(int i = 1; i < n; ++i){
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]); // buy
            s2[i] = s1[i-1] + prices[i]; // sell
        }
        return max(s0[n-1], s2[n-1]); // care about cooldown and buy
    }
};