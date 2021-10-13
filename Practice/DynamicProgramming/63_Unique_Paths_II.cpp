/*
Now consider if some obstacles are added to the grids. How many unique paths would there be?
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][0] = 1;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                if(!A[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m][n];
    }
};