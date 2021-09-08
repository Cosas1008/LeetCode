/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and 
return its area.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int prev = 0, side = 0, dp[n+1];
        memset(dp, 0x0, sizeof(dp));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int tmp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min( min(prev, dp[j-1]), dp[j] ) + 1;
                    side  = max(side, dp[j]);
                }else{
                    dp[j] = 0;
                }
                prev = tmp;
            }
        }
        return side*side;
    }
};