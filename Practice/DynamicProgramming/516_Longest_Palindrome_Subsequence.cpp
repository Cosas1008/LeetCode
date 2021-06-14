/*
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp, 0x0, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i+1][j+1] = (s[i] == s[n-1-j])? dp[i][j] + 1 : max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[n][n];
    }
};