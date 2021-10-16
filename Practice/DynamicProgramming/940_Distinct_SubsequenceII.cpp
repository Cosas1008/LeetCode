/*
Given a string s, return the number of distinct non-empty subsequences of s. 
Since the answer may be very large, return it modulo 109 + 7.
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

Ex:  S = "abab"
dp[0] = 2, as it counts ("", "a")
dp[1] = 4, as it counts ("", "a", "b", "ab");
dp[2] = 7 as it counts ("", "a", "b", "aa", "ab", "ba", "aba");
dp[3] = 12, as it counts ("", "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab").
We have that dp[3] counts dp[2], plus("b", "aa", "ab", "ba", "aba") with "b" added to it

*/
class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.length(), mod = 1e9 +  7;
        vector<int> dp(n+1);
        vector<int> last(26, -1);
        dp[0] = 1;
        for(int i = 0; i < n; ++i){
            int k = S[i] - 'a'; // key
            dp[i+1] = dp[i] * 2 % mod;
            if(last[k] >= 0)// if never seen before
                dp[i+1] -= dp[last[k]];
            dp[i+1] %= mod;
            last[k] = i;
        }
        dp[n]--; // remove ""
        return (dp[n] < 0)? dp[n] + mod : dp[n];
    }
    // Concise
    int distinctSubseqII(string S) {
        long last[26] = {}, mod = 1e9 + 7;
        for(char c : S)
            last[c - 'a'] = accumulate(begin(last), end(last), 1L) % mod;
        return accumulate(begin(last), end(last), 0L) % mod;
    }
};