/*
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1, 0));
        for(int i = 0; i < s.length(); i++)
            dp[0][i] = 1;
        for(int i = 1; i <= t.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1]? dp[i-1][j-1] : 0);
            }
        }
        return dp[t.length()][s.length()];
    }
};

// Optimize
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) // forward s
            for(int j = m; j >= 1; j--) // reverse t
                dp[j] += t[j-1] == s[i-1]? dp[j-1] : 0;
        return dp[m];
    }
};