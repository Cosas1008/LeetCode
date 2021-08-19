/*
Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        memset(dp,0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = (s[i -1] == '0')? 0 : dp[i-1];
            if(i > 1 && ((s[i - 2] == '1') || (s[i-2] == '2'  && s[i-1] <= '6'))){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};