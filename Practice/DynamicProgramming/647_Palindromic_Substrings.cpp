/*
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int count = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 1;
                }else if(i+1 == j){
                    dp[i][j] = s[i] == s[j]? 1 : 0;
                }else{
                    dp[i][j] = s[i] == s[j]? dp[i+1][j-1] : 0;
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};
// Understandable approach
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        bool dp[n][n];
        fill_n(*dp, n*n, false);
        
        // single letter
        for(int i = 0; i < n; ++i, ++ans)
            dp[i][i] = true;
        
        // double letters
        for(int i = 0; i < n - 1; ++i ){
            dp[i][i+1] = s[i] == s[i+1];
            ans += dp[i][i+1];
        }
        
        // other 3+ letters
        for(int len = 3; len <= n; ++len)
            for(int i = 0, j = i + len - 1; j < n; ++i, ++j){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                ans += dp[i][j];
            }
        
        return ans;
    }
};