// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
class Solution {
public:
    int minDistance(string A, string B) {
      int n = A.size();
      int m = B.size();
      if(n * m  == 0) return n + m;
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
      
      for(int i = 0; i < n+1; ++i)
        dp[i][0] = i;
      for(int j = 0; j < m+1; ++j)
        dp[0][j] = j;
      
      for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
          int left = dp[i-1][j] + 1;
          int down = dp[i][j-1] + 1;
          int left_down = dp[i-1][j-1] + (A[i-1] != B[j-1]);
          dp[i][j] = min(left, min(down, left_down));
          
        }
      }
      return dp[n][m];
    }
};