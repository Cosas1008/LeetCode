/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there are n stones in a pile. 
Players make a move consisting of removing any non-zero (square number) of stones in the pile.
*/
class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] means result of n = i
        vector<int> dp(n+1, false);
        for(int i = 1; i <= n; i++){
            for(int k = 1; k * k <= i; k++){
                if(!dp[i - k*k]){ // if there is any k that dp[i - k * k] == false, i could be the winner
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};