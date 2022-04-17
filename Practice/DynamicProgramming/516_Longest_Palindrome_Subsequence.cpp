/*
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/
// Another way
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
  }
};
// Bottom up DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> dp(n+1, vector<int>(n+1, 0));
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