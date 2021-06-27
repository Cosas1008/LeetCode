/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
*/
// DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        int k = n-1;
        while(k >= 0 && p[k] == '*'){
            dp[m][k--] = true;
        }
        dp[m][n] = true; // important set to match from back
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == p[j] || p[j] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }else if(p[j] == '*'){
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }
};