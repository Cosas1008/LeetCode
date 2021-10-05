/*
0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        for(int i = 1; i <= coins.size(); ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= amount; ++j){
                dp[i][j] = dp[i-1][j] + (j >= coins[i-1]? dp[i][j-coins[i-1]] : 0);
            }
        }
        return dp[coins.size()][amount];
    }
    // optimize
    int change(int amount, vector<int>& A){
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int a : A)
            for(int i = a; i <= amount; ++i)
                dp[i] += dp[i-a];
        return dp[amount];
    }
};