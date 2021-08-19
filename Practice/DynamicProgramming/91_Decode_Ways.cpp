/*
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.size();
        int dp[n+1];
        memset(dp,0,(n+1)*sizeof(int));
        dp[0] = 1;
        for(int i = 1; i <= s.size(); ++i)
        {
            dp[i] = (s[i -1] == '0')? 0 : dp[i-1];
            if(i > 1 && ((s[i - 2] == '1') || (s[i-2] == '2'  && s[i-1] <= '6'))){
                dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};