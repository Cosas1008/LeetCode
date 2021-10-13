/*
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Question : Why can't we use recursive
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++)
            dp[i][0] = 1;
        for(int j = 0; j <= n; j++)
            dp[0][j] = 1;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
    }
    // Optimize
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
    // Follow up recursive
    int uniquePaths(int m, int n){
        if(m <= 0 || n <= 0) return 0;
        return path(m-1, n-1);
    }
    int path(int m, int n){
        if(m < 0 || n < 0) return 0; // If move out of boundary return 0
        if(m == 0 || n == 0) return 1; // If hit boundary, guarantee to have a way to reach
        return path(m-1, n) + path(m, n-1);
    }
    // recursive + memo
    int uniquePaths(int m, int n){
        if(m <= 0 || n <= 0) return 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return path(m-1, n-1, memo);
    }
    int path(int m, int n, vector<vector<int>>& memo){
        if(m < 0 || n < 0) return 0; // If move out of boundary return 0
        if(m == 0 || n == 0) return 1; // If hit boundary, guarantee to have a way to reach
        if(memo[m][n]) return memo[m][n];
        return memo[m][n] = path(m-1, n) + path(m, n-1);
    }
};