/*
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Goal: maximum sum of like-time coefficient
Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

*/
class Solution {
public:
    // we will cook the dish with small satisfication, and leave the most satisfied dish in the end.
    int maxSatisfaction(vector<int>& S) {
        sort(S.begin(), S.end());
        int res = 0, total = 0, n = S.size();
        for(int i = n-1; i >= 0 && S[i] > -total; --i){
            total += S[i];
            res   += total;
        }
        return res;
    }
    // Knapsack 0-1
    int dp[501][501] = {};
    int dfs(vector<int>& sat, int p, int t){
        if(p >= sat.size()) return 0;
        if(dp[p][t]) return dp[p][t];
        return dp[p][t] = max(dfs(sat, p+1, t), sat[p] * t + dfs(sat, p+1, t+1));
    }
    int maxSatisfaction(vector<int>& S) {
        sort(S.begin(), S.end());
        return dfs(S, 0, 1);
    }
    // Greedy O(n log n)
    int maxSatisfaction(vector<int>& sat){
        sort(begin(sat), end(sat));
        int run_sum = accumulate(begin(sat), end(sat), 0), total_sum = 0;
        for(auto i = 0; i < sat.size(); ++i)
            total_sum += (i+1) * sat[i];
        for(auto i = 0; run_sum < 0 && i < sat.size(); ++i){
            total_sum -= run_sum;
            run_sum   -= sat[i];
        }
        return total_sum;
    }
};