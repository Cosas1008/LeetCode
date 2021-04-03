// Optimization 1-Memorize
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, 0x0, 1000);
        return min(minCost(cost, cost.size()-1), minCost(cost, cost.size()-2));
    }
    int minCost(vector<int>& cost, int n){
        if(n < 0) return 0;
        if(n == 0 || n == 1) return cost[n];
        if(dp[n] != 0) return dp[n];
        dp[n] = cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
        return dp[n];
    }
private:
    int dp[1000];
};
// Optimization 2 -Bottom Up DP
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        memset(dp, 0x0, n);
        for(int i = 0 ; i < n; i++){
            if(i < 2) dp[i] = cost[i];
            else dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};