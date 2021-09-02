/*
Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.
*/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        int n = jobDifficulty.size(), inf = 1e9, maxd;
        if(D > n) return -1;
        int dp[n+1];
        // memset(dp, inf, sizeof(dp)); // false
        memset(dp, 1000, sizeof(dp)); // Reason unclear
        dp[n] = 0;
        for(int d = 1; d <= D; d++){
            for(int i = 0; i <= n - d; i++){
                maxd = 0, dp[i] = inf;
                for(int j = i; j <= n - d; j++){
                    maxd = max( maxd, jobDifficulty[j]);
                    dp[i] = min(dp[i], maxd + dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};