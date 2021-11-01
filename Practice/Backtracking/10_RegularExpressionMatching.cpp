/*
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Input: s = "mississippi", p = "mis*is*p*."
Output: false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        ls = s.length(), lp = p.length();
        return dfs(s, p, 0, 0);
    }
    bool dfs(string& s, string& p, int si, int pi){
        if(si >= ls && pi >= lp) return true;
        if(pi >= lp) return false;
        bool match = si < ls && (s[si] == p[pi] || p[pi] == '.');
        if(pi + 1 < lp && p[pi+1] == '*'){
            return dfs(s, p, si, pi+2) || 
                (match && dfs(s, p, si+1, pi));
        }
        return match? dfs(s, p, si+1, pi+1) : false;
    }
private:
    int ls, lp;
};

// Optimized Recursive call
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1] == '*')
            return (isMatch(s,p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
}


// DP 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int j=0; j < n; j++){
            if(p[j] == '*' && dp[0][j-1]){
                dp[0][j+1] = true;
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '.' || p[j-1] == s[i-1])
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1] == '*'){
                    if(p[j-2] != s[i-1] && p[j-2] != '.'){
                        dp[i][j] = dp[i][j-2];
                    }else{
                        dp[i][j] = (dp[i][j-1] || dp[i-1][j] || dp[i][j-2]);
                    }
                }
            }
        }
        return dp[m][n];
    }
}