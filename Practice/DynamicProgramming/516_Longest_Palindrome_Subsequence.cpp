/*
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/
// Bottom up DP
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
// Top Down DP
class Solution {
public:
    int longestPalindromeSubseq(string s){
        return dp(s, 0, s.size() - 1);
    }
    int dp(const string& s, int l, int r){
        if(l > r) return 0;
        if(l == r) return 1;
        if(memo[l][r] != 0) return memo[l][r];
        if(s[l] == s[r])
            return memo[l][r] = dp(s, l+1, r-1) + 2; // match
        return memo[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    }
private:
    int memo[1000][1000];
}