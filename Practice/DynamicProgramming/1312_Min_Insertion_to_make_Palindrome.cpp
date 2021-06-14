/*
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Same as 516 Longest Palindrome Subsequence
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp, 0x0, sizeof(dp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i+1][j+1] = (s[i] == s[n-1-j])? dp[i][j] + 1 : max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return n - dp[n][n];
    }
};