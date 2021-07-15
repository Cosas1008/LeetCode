/*
There is a strange printer with the following two special properties:
The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
*/
class Solution {
public:
    int strangePrinter(string s) {
        // remove repeated continuous character
        if(s.length() <= 1) return s.length();
        char c = s[0] - 1;
        string ss;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != c){
                ss += s[i];
            }
            c = s[i];
        }
        s = ss;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // for each char, need to flip once, if continuous same char -> make it one flip
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(i < n-1){
                dp[i][i+1] = s[i] == s[i+1]? 1 : 2;
            }
        }
        //
        for(int len = 2; len < n; len++){
            for(int start = 0; start < n - len; start++){
                dp[start][start+len] = len+1;
                for(int k = 0; k < len; k++){
                    int temp = dp[start][start+k] + dp[start+k+1][start+len];
                    dp[start][start+len] = min(dp[start][start+len],
                        (s[start+k] == s[start+len]? temp - 1 : temp));
                }
            }
        }
        return dp[0][n-1];
    }
};