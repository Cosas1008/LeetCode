/*
Find the maximum profit you can achieve. You may complete at most two transactions.
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Find the maximum profit you can achieve. You may complete at most two transactions.
*/
class Solution {
public:
    // Optimize 3: Simple Solution
    int maxProfit(vector<int>& prices) {
        int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
        for(int& p : prices){
            buy1  = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2  = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2;
    }
    // DP  O(kn^2), space complexity is O(kn).
    int maxProfit(vector<int>& prices) {
        // for k transactions, on i-th day
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0)); // because we ask for at most 2 transactions
        for(int k = 1; k <= 2; ++k){
            for(int i = 1; i < n; ++i){
                int minP = prices[0];
                for(int j = 1; j <= i; ++j)
                    minP = min(minP, prices[j] - dp[k-1][j-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - minP);
            }
        }
        return dp[2][n-1];
    }
    // Optimize 1 : if we swap two 'for' loop
    // Time O(kn) Space O(kn)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0)); // because we ask for at most 2 transactions
        vector<int> minP(3, prices[0]); // for k + 1 space
        for(int i = 1; i < n; ++i){
            for(int k = 1; k <= 2; ++k){
                min[k] = min(min[k], prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - min[k]);
            }
        }
        return dp[2][n-1];
    }
    // Optimize 2 : dp[k][i] is only dependent on previous dp[k][i-1]
    // Time O(kn) Space O(k)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(3, 0);
        vector<int> minP(3, prices[0]); // for k + 1 space
        for(int i = 1; i < n; ++i){
            for(int k = 1; k <= 2; ++k){
                minP[k] = min(minP[k], prices[i] - dp[k-1]);
                dp[k]  = max(dp[k], prices[i] - minP[k]);
            }
        }
        return dp[2];
    }
};