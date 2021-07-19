/*
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i = 0, j = 0;
        string ans;
        for( char c :  lcs(str1, str2)){
            while(str1[i] != c){
                ans += str1[i++];
            }
            while(str2[j] != c){
                ans += str2[j++];
            }
            ans += c; i++; j++;
        }
        return ans + str1.substr(i) + str2.substr(j);
    }
    string lcs(string& A, string& B){
        int n = A.length();
        int m = B.length();
        vector<vector<string>> dp(n+1, vector<string>(m+1, ""));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i] == B[j]){
                    dp[i+1][j+1] = dp[i][j] + A[i];
                }else{
                    dp[i+1][j+1] = dp[i+1][j].size() > dp[i][j+1].size() ? dp[i+1][j] : dp[i][j+1];
                }
            }
        }
        return dp[n][m];
    }
};

// DP + backtracking (Optimized)
class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        string res = "";
        vector<vector<short>> dp(a.size() + 1, vector<short>(b.size() + 1));

        for (int i = 1; i <= a.size(); ++i)
            for (int j = 1; j <= b.size(); ++j)
                dp[i][j] =  (a[i - 1] == b[j - 1])? dp[i - 1][j - 1] + 1: max(dp[i - 1][j], dp[i][j - 1]);
    
        for (int i = a.size(), j = b.size(); i || j; ) {
            // cout << res  << endl;
            if (i > 0 && dp[i][j] == dp[i - 1][j]) res = a[--i] + res;
            else if (j > 0 && dp[i][j] == dp[i][j - 1]) res = b[--j] + res;
            else res = a[--i] + res, --j;
        }
    return res;
    }
};