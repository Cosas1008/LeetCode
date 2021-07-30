/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
*/
class Solution {
public:
    // method 1 : hash
    string longestPrefix(string s) {
        // define hash function as 1 + x^1 + x^2 + .... x^n ( where x is 26 characters )
        long h1, h2, mul = 1, len = 0, mod = 1e9+7;
        h1 = h2 = 0;
        for(int i = 0, j = s.length() - 1; j > 0; i++, j--){
            int first = s[i] - 'a', second = s[j] - 'a';
            h1 = (h1 * 26 + first) % mod;
            h2 = (h2 + mul * second) % mod;
            mul = (mul * 26) % mod;
            if(h1 == h2)
                len = i + 1;
        }
        return s.substr(0,len);
    }
    // method 2: KMP
    string longestPrefix(string &s) {
        vector<int> dp(s.length());
        int j = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[j])
                dp[i] = ++j;
            else if (j > 0) {
                j = dp[j - 1];
                --i;
            }
        }
        return s.substr(0, j);
    }
};