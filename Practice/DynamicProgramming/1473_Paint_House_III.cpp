/*
A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:

houses[i]: is the color of the house i, and 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.
*/
class Solution {
public:
    // bottom-up Time: O(n * n * m * target) Space: O(n * m * target) (can be optimized to O(n * target))
    int dp[101][21][101] = {};
    int MAX = 1000001;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            int ans = solve(houses, cost, m, n, target, 0, 0);
            return ans < MAX ? ans : -1;
    }
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int p){
        if(i == m || target < 0){
            if(target == 0)
                return 0;
            
            return MAX;
        }
        if(dp[i][p][target] != 0)
            return dp[i][p][target];
        
        int ans = MAX;
        if(houses[i] == 0){
            for(int k = 1; k <= n; k++){ //k->new color
                ans = min(ans, solve(houses, cost, m, n, target - (k != p) , i+1, k) + cost[i][k-1]);   
            }
        }else{
            ans = solve(houses, cost, m, n, target - (houses[i] != p), i+1, houses[i]);
        }
        return dp[i][p][target] = ans;
    }
};