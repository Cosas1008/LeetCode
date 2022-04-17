/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
      int n1 = s1.length(), n2 = s2.length();
      vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
      for(int i = n1-1; i >= 0; i--)
        dp[i][n2] = dp[i+1][n2] + s1[i];
      for(int i = n2-1; i >= 0; i--)
        dp[n1][i] = dp[n1][i+1] + s2[i];
      
      for(int i = n1-1; i >= 0; i--){
        for(int j = n2-1; j >= 0; j--){
          if(s1[i] == s2[j])
            dp[i][j] = dp[i+1][j+1];
          else
            dp[i][j] = min(dp[i+1][j] + s1[i], dp[i][j+1] + s2[j]);
        }
      }
      return dp[0][0];
    }
};