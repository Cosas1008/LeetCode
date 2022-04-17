/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
      int n = word1.size(), m = word2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
          dp[i+1][j+1] = (word1[i] == word2[j])? dp[i][j] + 1 : max(dp[i][j+1], dp[i+1][j]);
        }
      }
      return m + n - 2 * dp[n][m];
    }
};